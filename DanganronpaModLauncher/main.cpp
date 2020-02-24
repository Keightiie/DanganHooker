#include <string>
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

int Game = 0;
char DanganHookerName[] = "DanganHooker.dll";
const char * ProcessNames[] = { "DR1_us.exe", "DR2_us.exe", "game.exe" };
const char * GameIDs[] = { "413410", "413420", "555950" };
static string Path;

typedef HINSTANCE(*fpLoadLibrary)(char *);

int main(int argc, char* argv[])
{
	using std::string;
	char basePath[255] = "";
	_fullpath(basePath, argv[0], sizeof(basePath));
	Path = basePath;
	Path = Path.substr(0, Path.find_last_of("\\/"));
	Path.append("\\");
	
	DWORD processID = NULL;
	
	PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
	HANDLE hProcSnap;
	char steamUrl[64] = "";
	std::snprintf(steamUrl, sizeof(steamUrl), "steam://rungameid/%s", GameIDs[Game]);
	ShellExecute(NULL, "open", steamUrl, NULL, NULL, SW_SHOWDEFAULT);
	while(!processID)
	{
		system("CLS");
		cout << "Looking for " << ProcessNames[Game] << ", please wait..." << endl;
		cout << "If the game doesn't launch, make sure you have it installed on steam." << endl;
		hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		if(Process32First(hProcSnap, &pe32))
		{
			do
			{	
				if(!strcmp(pe32.szExeFile, ProcessNames[Game]))
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

	char *DLLPath = &Path[0];

	strcat_s(DLLPath, 250, DanganHookerName);

	paramAddr = VirtualAllocEx(hProc, 0, strlen(DLLPath) + 1, MEM_COMMIT, PAGE_READWRITE);

	bool MemoryWritten = WriteProcessMemory(hProc, paramAddr, DLLPath, strlen(DLLPath) + 1, NULL);

	CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryAddr, paramAddr, 0, 0);

	CloseHandle(hProc);
	//Sleep(5000);
	//DebugActiveProcessStop(ProcessID);
	return MemoryWritten;

};