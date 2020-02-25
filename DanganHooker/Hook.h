#pragma once
#include <Windows.h>
#include <fstream>
#include <iostream>
#include "console.h"

class Hook
{
private:
	bool Hooked = false;

	//Initiate the Hooking Process
	bool InitiateHooks();
	bool InitiateOpcodes();

	//Write to Memory
	bool DetourInstructions(DWORD HookAddress, DWORD HookAddressEnd, void * FunctionToDetour);
	bool WritePointer(DWORD PointerAddress, DWORD Pointer);
	bool WriteByte(DWORD ByteAddress, BYTE Byte);



public:
	void Init();

	//Read from Memory
	DWORD ReadPointer(DWORD PointerAddress);


};

