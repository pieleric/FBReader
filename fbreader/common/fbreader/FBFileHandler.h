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

#ifndef __FBFILEHANDLER_H__
#define __FBFILEHANDLER_H__

#include <abstract/ZLOpenFileDialog.h>

#include "../description/BookDescription.h"

class FBFileHandler : public ZLFileHandler {

public:
	FBFileHandler() FB_DIALOG_SECTION;
	~FBFileHandler() FB_DIALOG_SECTION;

	bool isFileVisible(const std::string &shortFileName, bool dir) const FB_DIALOG_SECTION;
	const std::string &pixmapName(const std::string &shortFileName, bool dir) const FB_DIALOG_SECTION;
	void accept(const std::string &fullFileName, bool dir) const FB_DIALOG_SECTION;

	BookDescription *description() const FB_DIALOG_SECTION;

private:
	mutable BookDescription *myDescription;
};

inline FBFileHandler::FBFileHandler() : myDescription(0) {}
inline FBFileHandler::~FBFileHandler() {}
inline BookDescription *FBFileHandler::description() const { return myDescription; }

#endif /* __FBFILEHANDLER_H__ */
