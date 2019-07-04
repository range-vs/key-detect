#include "Controller.h"

void Controller::clear()
{
	UnhookWindowsHookEx(hCBTHook);
	VirtualFree(callbackGlobalHook, sizeof(Thunk), MEM_DECOMMIT);
}

void Controller::saveModelFromFile()
{
	SaveFileDialog saveFileDialog(console->getDescriptor());
	if (saveFileDialog.action())
	{
		sendDataForConsole();
		wofstream file(saveFileDialog.getPath());
		file.imbue(locale("rus_rus.1251"));
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

Controller::Controller(HINSTANCE hInst):richEditConsole(new RichEdit()), console(new Console()), hInst(hInst), model(new ConsoleData()){ }

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
	callbackGlobalHook = reinterpret_cast<Thunk*>(VirtualAlloc(NULL,sizeof(Thunk),MEM_COMMIT,PAGE_EXECUTE_READWRITE));
	if (!callbackGlobalHook)
	{
		clear();
		throw wstring(L"Error alloc memory for hook proc!");
	}
	callbackGlobalHook -> stub1 = 0x0D8D;
	callbackGlobalHook -> nThisPtr = reinterpret_cast<unsigned long>(ev.get());
	callbackGlobalHook -> stub2 = 0xB8;
	callbackGlobalHook -> nJumpProc = CustomCast::brute_cast<unsigned long>(&GlobalHook::MsgProc);
	callbackGlobalHook -> stub3 = 0xE0FF;
	FlushInstructionCache(GetCurrentProcess(), callbackGlobalHook, sizeof(Thunk));
	// send data for dll
	ev->createEventData(console);
	// create hook
	HHOOK hCBTHook = SetWindowsHookEx(WH_KEYBOARD_LL, reinterpret_cast<HOOKPROC>(callbackGlobalHook), dll->getHinstance(), NULL); // устанавливаем хук на нажатие клавиш
	ev->setHHook(hCBTHook);
	// add actions menu
	console->addMenuAction(CONSOLE_MAINMENU_SAVELOG, function<void()>(std::bind(&Controller::saveModelFromFile, this)));
	console->addMenuAction(CONSOLE_MAINMENU_CLEARLOG, function<void()>(std::bind(&Controller::clearModelAndRichEdit, this)));
	console->addMenuAction(CONSOLE_MENU_ABOUT, function<void()>(std::bind(&Controller::showAbout, this)));
}

MSG Controller::run()
{
	MSG msg;
	ShowWindow(console->getDescriptor(), SW_SHOW); 
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
			sendDataForConsole();
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

// Выложить на гитхаб
// описать: MVC, фабричный метод, синглетон, dll, solid, ООП

// Тест с самоизменяющимся кодом: полностью избавиться от синглетона, передать во все события IHook*(или умный *)
// проверить, что хук - события успешно отлавливаются и система работает