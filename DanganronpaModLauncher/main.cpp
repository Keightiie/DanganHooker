#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

using namespace std;
enum DRGames
{
	DR1 = 0,
	DR2 = 1,
	UDG = 2,
	V3 = 3
};

bool InjectDLL(DWORD ProcessID);

char DanganHookerName[] = "DanganHooker.dll";
char ProcessName[] = "DR2_us.exe";
char ProcessNamev3[] = "Dangan3Win.exe";
typedef HINSTANCE(*fpLoadLibrary)(char *);

int main() 
{
	DWORD processID = NULL;

	PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
	HANDLE hProcSnap;
	//ShellExecute(NULL, "open", "steam://rungameid/412420", NULL, NULL, SW_SHOWDEFAULT);
	while(!processID)
	{
		system("CLS");
		cout << "Looking for " << ProcessName << ", please wait..." << endl;
		cout << "If the game doesn't launch, make sure you have it installed on steam." << endl;
		hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		if(Process32First(hProcSnap, &pe32))
		{
			do
			{
				if(!strcmp(pe32.szExeFile, ProcessName))
				{
					processID = pe32.th32ProcessID;
					break;
				}
				
			} while (Process32Next(hProcSnap, &pe32));
		}
		Sleep(1000); 


	}

	while(!InjectDLL(processID))
	{
		system("CLS");
		cout << "DanganHooker failed to hook, retrying..." << endl;
		Sleep(1000);
	}

	cout << "DanganHooker has been hooked!" << endl;
	cout << "ModLauncher will now close. Enjoy!" << endl;

	CloseHandle(hProcSnap);
	Sleep(1500);

	return 0;
}

bool InjectDLL(DWORD ProcessID)
{
	//DebugActiveProcess(ProcessID);
	HANDLE hProc;
	LPVOID paramAddr;

	HINSTANCE hDll = LoadLibrary("KERNEL32");

	fpLoadLibrary LoadLibraryAddr = (fpLoadLibrary)GetProcAddress(hDll, "LoadLibraryA");

	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessID);

	char DLLPath[250] = "E:\\Users\\ziell\\source\\repos\\DanganHooker\\Release\\";

	strcat_s(DLLPath, 250, DanganHookerName);

	paramAddr = VirtualAllocEx(hProc, 0, strlen(DLLPath) + 1, MEM_COMMIT, PAGE_READWRITE);

	bool MemoryWritten = WriteProcessMemory(hProc, paramAddr, DLLPath, strlen(DLLPath) + 1, NULL);



	CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryAddr, paramAddr, 0, 0);



	CloseHandle(hProc);
	//Sleep(5000);
	//DebugActiveProcessStop(ProcessID);
	return MemoryWritten;

};