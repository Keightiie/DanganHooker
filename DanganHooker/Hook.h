#pragma once
#include <Windows.h>
#include <fstream>
#include <iostream>
#include "console.h"

class Hook
{
private:
	bool Hooked = false;
	DWORD BaseAddress = 0;
	DWORD AbsolouteAddress(DWORD ExeAddress);

	//Initiate the Hooking Process
	bool InitiateHooks();
	bool InitiateOpcodes();

	//Write to Memory
	bool DetourInstructions(DWORD HookAddress, DWORD HookAddressEnd, void * FuncitonToDetour);
	bool WritePointer(DWORD PointerAddress, DWORD Pointer);
	bool WriteByte(DWORD ByteAddress, BYTE Byte);



public:
	void Init();

	//Read from Memory
	DWORD ReadPointer(DWORD PointerAddress);


};

