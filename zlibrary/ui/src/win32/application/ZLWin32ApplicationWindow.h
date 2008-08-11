/*
 * Copyright (C) 2007-2008 Geometer Plus <contact@geometerplus.com>
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __ZLWIN32APPLICATIONWINDOW_H__
#define __ZLWIN32APPLICATIONWINDOW_H__

#include <map>

#include <windows.h>
#include <commctrl.h>

#include <ZLUnicodeUtil.h>

#include "../../../../core/src/desktop/application/ZLDesktopApplicationWindow.h"

class ZLWin32ViewWidget;

class ZLWin32ApplicationWindow : public ZLDesktopApplicationWindow { 

private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static ZLWin32ApplicationWindow *ourApplicationWindow;

public:
	ZLWin32ApplicationWindow(ZLApplication *application);
	~ZLWin32ApplicationWindow();

private:
	ZLViewWidget *createViewWidget();
	void addToolbarItem(ZLToolbar::ItemPtr item);
	void close();

	void grabAllKeys(bool grab);

	void setCaption(const std::string &caption);

	void setHyperlinkCursor(bool hyperlink);

	bool isFullscreen() const;
	void setFullscreen(bool fullscreen);

	void init();

	void setToggleButtonState(const ZLToolbar::ToggleButtonItem &button);
	void setToolbarItemState(ZLToolbar::ItemPtr item, bool visible, bool enabled);

	void updateTextField(int idCommand);

public:
	HWND mainWindow() const;
	void blockMouseEvents(bool block);
	bool mouseEventsAreBlocked() const;
	void setWait(bool wait);
	void resetFocus();
	void updateCursor() const;

private:
	LRESULT mainLoopCallback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	void onToolbarButtonPress(int index);
/*
	void handleKeyEventSlot(GdkEventKey *event);
	void handleScrollEventSlot(GdkEventScroll *event);
*/

private:
	class TextEditParameter : public VisualParameter {

	public:
		TextEditParameter(HWND toolbar, int idCommand, const ZLToolbar::TextFieldItem &item);
		HWND handle() const;

	private:
		std::string internalValue() const;
		void internalSetValue(const std::string &value);

	private:
		HWND myTextEdit;
	};

private:
	ZLUnicodeUtil::Ucs2String myClassName;

	HWND myMainWindow;
	HWND myToolbar;

	ZLWin32ViewWidget *myWin32ViewWidget;

	std::map<int,ZLToolbar::ItemPtr> myTBItemByActionCode;
	std::map<ZLToolbar::ItemPtr,int> mySeparatorNumbers;
	std::map<std::string,int> myActionCodeById;
	std::map<std::string,int> myTextFieldCodeById;
	std::map<int,HWND> myTextFields;

	bool myBlockMouseEvents;
	int myKeyboardModifierMask;

	bool myFullScreen;
	bool myWait;

	HCURSOR myCursor;

friend class ZLWin32TimeManager;
};

#endif /* __ZLWIN32APPLICATIONWINDOW_H__ */
