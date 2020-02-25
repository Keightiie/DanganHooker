#include "main.h"
#include "console.h"
#include "data.h"
#include "Hook.h"
#include "MemoryAddresses.h"

using namespace std;

DWORD WINAPI MainThread(LPVOID param)
{
	Hook DRHook = Hook();

	char path[256];

	GetModuleFileName(nullptr, path, sizeof(path));

	if (strstr(path, "DR1_us.exe") != nullptr)
	{
		Data::Game = Data::Games::DR1;
		CommonAddresses::BaseAddress = DWORD(GetModuleHandleA("DR1_us.exe"));
		
	}
	else if (strstr(path, "DR2_us.exe") != nullptr)
	{
		Data::Game = Data::Games::DR2;
		CommonAddresses::BaseAddress = DWORD(GetModuleHandleA("DR2_us.exe"));
	}
	else
	{
		Console::WriteLine("[DEBUG] Unknown game path %s, ending.", path);
		Sleep(5000);
		FreeLibraryAndExitThread((HMODULE)param, 0);
		return 0;
	}
	
	Data::GamePath = path;
	Data::GamePath = Data::GamePath.substr(0, Data::GamePath.find_last_of("\\/"));
	Data::GamePath.append("\\");
	
	DRHook.Init();

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

			Console::WriteLine("[DEBUG] DLL Process Attached.");
			CreateThread(0, 0, MainThread, hModule, 0, 0);

		break;

		case DLL_PROCESS_DETACH:
			Console::WriteLine("[DEBUG] DLL Process Detached.");
		break;
	}



	return TRUE;
}