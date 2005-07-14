/*
 * Copyright (C) 2005 Nikolay Pultsin <geometer@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <abstract/ZLFSManager.h>
#include <abstract/ZLInputStream.h>

#include "ZLXMLReaderInternal.h"
#include "../ZLXMLReader.h"
#include "../EncodingReader.h"

static void fCharacterDataHandler(void *userData, const char *text, int len) {
	((ZLXMLReader*)userData)->characterDataHandler(text, len);
}

static void fStartElementHandler(void *userData, const char *name, const char **attributes) {
	((ZLXMLReader*)userData)->startElementHandler(((ZLXMLReader*)userData)->tag(name), attributes);
}

static void fEndElementHandler(void *userData, const char *name) {
	((ZLXMLReader*)userData)->endElementHandler(((ZLXMLReader*)userData)->tag(name));
}

static int fUnknownEncodingHandler(void *, const XML_Char *name, XML_Encoding *info) {
	bool code = false;
	const std::vector<std::string> &encodings = ZLXMLReader::knownEncodings();
	for (std::vector<std::string>::const_iterator it = encodings.begin(); it != encodings.end(); it++) {
		if (strcasecmp(name, it->c_str()) == 0) {
			EncodingReader er(ZLXMLReader::encodingDescriptionPath() + '/' + *it);
			code = er.fillTable(info->map);
			break;
		}
	}
	return code ? XML_STATUS_OK : XML_STATUS_ERROR;
}

static void parseDTD(XML_Parser parser, const std::string &fileName) {
	XML_Parser entityParser = XML_ExternalEntityParserCreate(parser, 0, 0);
	shared_ptr<ZLInputStream> entityStream = ZLFile(fileName).inputStream();
	if (!entityStream.isNull() && entityStream->open()) {
		const size_t BUFSIZE = 2048;
		char buffer[BUFSIZE];
		size_t length;
		do {
			length = entityStream->read(buffer, BUFSIZE);
			if (XML_Parse(entityParser, buffer, length, 0) == XML_STATUS_ERROR) {
				break;
      }
    } while (length == BUFSIZE);
	}
	XML_ParserFree(entityParser);
}

ZLXMLReaderInternal::ZLXMLReaderInternal(ZLXMLReader &reader, const char *encoding) : myReader(reader) {
	myParser = XML_ParserCreate(encoding);
	myInitialized = false;
}

ZLXMLReaderInternal::~ZLXMLReaderInternal() {
	XML_ParserFree(myParser);
}

void ZLXMLReaderInternal::init() {
	if (!myInitialized) {
		myInitialized = true;
		XML_UseForeignDTD(myParser, XML_TRUE);

		const std::vector<std::string> &dtds = myReader.externalDTDs();
		for (std::vector<std::string>::const_iterator it = dtds.begin(); it != dtds.end(); it++) {
			parseDTD(myParser, *it);
		}

		XML_SetUserData(myParser, &myReader);
		XML_SetStartElementHandler(myParser, fStartElementHandler);
		XML_SetEndElementHandler(myParser, fEndElementHandler);
		XML_SetCharacterDataHandler(myParser, fCharacterDataHandler);
    XML_SetUnknownEncodingHandler(myParser, fUnknownEncodingHandler, NULL);
	}
}

bool ZLXMLReaderInternal::parseBuffer(const char *buffer, size_t len) {
	return XML_Parse(myParser, buffer, len, 0) != XML_STATUS_ERROR;
}
