#pragma once

#include "stdafx.h"
#include "RichEdit.h"
#include "Console.h"
#include "../hook_key/GlobalHook.h"
#include "SaveFileDialog.h"
#include "About.h"
#include "Thunk.h"

class Controller;

using SmartController = usmart_pointer<Controller>;
using CreateHookType = GlobalHook * (*)();
using GetHookProcType = HOOKPROC (*)();
using SmartGlobalHook = shared_ptr<GlobalHook>;

class Controller: public IInitialize
{
	HINSTANCE hInst;
	SmartRichEdit richEditConsole;
	SmartHookWindow console;
	HOOKPROC hProc;
	HHOOK hCBTHook;
	usmart_pointer<LoaderDll> dll;
	SmartGlobalHook ev;
	SmartConsoleData model;
	SmartThunkCreator callbackGlobalHook;

	void sendDataForConsole();
	Controller(const Controller&);
	Controller& operator=(const Controller&);
public:
	Controller(HINSTANCE);
	void init();
	MSG run();
	void clear();

	void saveModelFromFile();
	void clearModelAndRichEdit();
	void showAbout();

	void errorClear();

	~Controller();
};
