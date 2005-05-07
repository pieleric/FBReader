/*
 * FBReader -- electronic book reader
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

#ifndef __FB2READER_H__
#define __FB2READER_H__

#include <abstract/ZLXMLReader.h>

class FB2Reader : public ZLXMLReader {

public:
//protected:
	enum TagCode {
		_P,
		_SUBTITLE,
		_CITE,
		_TEXT_AUTHOR,
		_DATE,
		_SECTION,
		_V,
		_TITLE,
		_POEM,
		_STANZA,
		_EPIGRAPH,
		_ANNOTATION,
		_SUB,
		_SUP,
		_CODE,
		_STRIKETHROUGH,
		_STRONG,
		_EMPHASIS,
		_A,
		_IMAGE,
		_BINARY,
		_BODY,
		_EMPTY_LINE,
		_TITLE_INFO,
		_BOOK_TITLE,
		_AUTHOR,
		_LANG,
		_FIRST_NAME,
		_MIDDLE_NAME,
		_LAST_NAME,
		_UNKNOWN
	};

protected:
	FB2Reader() FORMATS_SECTION;
	
public:
	~FB2Reader() FORMATS_SECTION;
	const Tag *tags() const FORMATS_SECTION;
};

inline FB2Reader::FB2Reader() {}
inline FB2Reader::~FB2Reader() {}

#endif /* __FB2READER_H__ */
