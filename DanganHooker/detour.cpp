#include "Detour.h"
#include "main.h"
#include "Console.h"
#include <string>

bool Detour::Hook(DWORD hookAddress, void * replacementFunc, int length)
{
	if (length < 5)
	{
		return false;
	}

	DWORD AbsoluteAddress = GetExactAddress(hookAddress);
	Console::Write("Replacing instructions at: ");
	Console::WriteLine(std::to_string(AbsoluteAddress).c_str());

	void * funcToDetour = (void*)AbsoluteAddress;

	DWORD curProtection;
	VirtualProtect(funcToDetour, length, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(funcToDetour, 0x90, length);

	DWORD relativeAddress = ((DWORD)replacementFunc - (DWORD)funcToDetour) - 5;

	//returnAddress = (DWORD)funcToDetour + length;

	*(BYTE*)funcToDetour = 0xE9;
	*(DWORD*)((DWORD)funcToDetour + 1) = relativeAddress;

	DWORD temp;
	VirtualProtect(funcToDetour, length, curProtection, &temp);

	return true;
}

DWORD Detour::GrabPointer(DWORD hookAddress)
{
	DWORD AbsoluteAddress = GetExactAddress(hookAddress);
	DWORD address = *(DWORD*)(AbsoluteAddress);
	return address;
}

DWORD Detour::GetExactAddress(DWORD relativeAddress)
{
	DWORD AbsoluteAddress = relativeAddress + main::ExeBaseAddress + 0x1000;
	return AbsoluteAddress;
}

bool Detour::HookStringPtr(DWORD hookAddress, DWORD replacementPtr)
{

	DWORD AbsoluteAddress = GetExactAddress(hookAddress);
	Console::Write("Replacing string pointer at: ");
	Console::WriteLine(std::to_string(AbsoluteAddress).c_str());

	*(DWORD*)AbsoluteAddress = replacementPtr;



	return true;
}

bool Detour::WriteByte(DWORD ByteAdress, char NewByte)
{
	DWORD AbsoluteAddress = GetExactAddress(ByteAdress);
	//char* result = reinterpret_cast<char*>(AbsoluteAddress);
	//*result = NewByte;


	char * ByteToWriteTo = (char*)AbsoluteAddress;
	DWORD curProtection;
	VirtualProtect(ByteToWriteTo, 1, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(ByteToWriteTo, NewByte, 1);

	DWORD temp;
	VirtualProtect(ByteToWriteTo, 1, curProtection, &temp);

	return true;
}


