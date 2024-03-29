﻿#include "Controller.h"

void Controller::clear()
{
	UnhookWindowsHookEx(hCBTHook);
}

void Controller::saveModelFromFile()
{
	SaveFileDialog saveFileDialog(console->getDescriptor());
	if (saveFileDialog.action())
	{
		sendDataForConsole();
		wofstream file(saveFileDialog.getPath());
		locale ruLocale("rus_rus.1251");
		file.imbue(ruLocale);
		copy(model->getData().begin(), model->getData().end(), std::ostream_iterator<wstring, wchar_t>(file));
	}
}

void Controller::clearModelAndRichEdit()
{
	SendMessageA(richEditConsole->getDescriptor(), WM_SETTEXT, WPARAM(0), LPARAM(L""));
	model->getData().clear();
}

void Controller::showAbout()
{
	About about(console->getDescriptor(), L"О программе", L"\"Перехватчик системных нажатий\"\nСоздатель: range (Трубников Иван), 2019 v 0.5 (c)");
	about.show();
}

void Controller::errorClear()
{
	DestroyWindow(console->getDescriptor());
}

Controller::Controller(HINSTANCE hInst):richEditConsole(new RichEdit()), console(new Console()), hInst(hInst), model(new ConsoleData()),
hProc(NULL), hCBTHook(NULL){ }

void Controller::init()
{
	console->init(NULL, hInst);
	richEditConsole->init(console->getDescriptor(), hInst);
	console->addControl(richEditConsole);

	dll.reset(new LoaderDll(L"hook_key.dll"));
	CreateHookType pEntryFunction = (CreateHookType)dll->getExportMember(L"CreateHook");
	if (!pEntryFunction)
	{
		clear();
		throw wstring(L"No load function CreateHook");
	}
	ev.reset(pEntryFunction());
	if (!ev)
	{
		clear();
		throw wstring(L"No create object GeneralHook");
	}
	ev->init();
	// create callback non-static function
	callbackGlobalHook.reset(new ThunkCreator());
	callbackGlobalHook->createNonStaticCallbackFunction(ev.get(), &GlobalHook::MsgProc);
	// send data for dll
	ev->createEventData(console);
	// create hook
	HHOOK hCBTHook = SetWindowsHookEx(WH_KEYBOARD_LL, reinterpret_cast<HOOKPROC>(callbackGlobalHook->getCallbackMethod()), dll->getHinstance(), NULL); // устанавливаем хук на нажатие клавиш
	ev->setHHook(hCBTHook);
	// add actions menu
	console->addMenuAction(CONSOLE_MAINMENU_SAVELOG, function<void()>(std::bind(&Controller::saveModelFromFile, this)));
	console->addMenuAction(CONSOLE_MAINMENU_CLEARLOG, function<void()>(std::bind(&Controller::clearModelAndRichEdit, this)));
	console->addMenuAction(CONSOLE_MENU_ABOUT, function<void()>(std::bind(&Controller::showAbout, this)));
}

MSG Controller::run(int mode_show)
{
	MSG msg;
	ShowWindow(console->getDescriptor(), mode_show);
	UpdateWindow(console->getDescriptor());
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (msg.message == WM_QUIT)
			break;
		else
		{
			Sleep(10);
			sendDataForConsole();
		}
	}
	return msg;
}

void Controller::sendDataForConsole()
{
	if (ev->getEvents().empty())
		return;
	for (auto& e : ev->getEvents())
		model->addData(e->createData());
	ev->getEvents().clear();
	console->mailingEvents(model);
	model->clearNewCountData();
}

Controller::~Controller()
{
	this->clear();
}

// TODO: тест - попробовать вызывать диалог сохранения файла с помощью COM C++ MS