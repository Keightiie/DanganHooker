#include "main.h"
#include "console.h"
#include "detour.h"
#include "sound.h"
#include "data.h"
#include <WinUser.h>

using namespace std;
DWORD main::ExeBaseAddress = 0x0;



int DebugLog(char const* const Format, ...)
{
	va_list va; // [esp+38h] [ebp+10h]

	va_start(va, Format);
	int v7;
	memset(&v7, 0, 0x1Cu);

	Console::WriteLine(va_arg(va, char *));
	return 0;
}

DWORD WINAPI MainThread(LPVOID param)
{
	Data::HookBGFileNames();
	Functions::HookFunctions();

	//Data::HookBGFileNames();

	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE)) break;
		//if (GetAsyncKeyState(VK_RETURN)) Movie(2);
		Sleep(50);
	}

	FreeLibraryAndExitThread((HMODULE)param, 0);

	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
	Console::Init();

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:

		main::ExeBaseAddress = (DWORD)GetModuleHandleA("DR2_us.exe");

		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;
	}

	return TRUE;
}