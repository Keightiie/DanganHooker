#include "main.h"
#include "console.h"
#include "Hook.h"

using namespace std;

DWORD WINAPI MainThread(LPVOID param)
{
	Hook DRHook = Hook();
	DRHook.Init(1);

	while (true)
	{
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

			Console::WriteLine("[DEBUG] DLL Process Attatched.");
			CreateThread(0, 0, MainThread, hModule, 0, 0);

		break;

		case DLL_PROCESS_DETACH:
			Console::WriteLine("[DEBUG] DLL Process Detached.");
		break;
	}



	return TRUE;
}