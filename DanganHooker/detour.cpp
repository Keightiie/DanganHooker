#include "Detour.h"
#include "main.h"
#include "Console.h"
#include <string>

static const char * bg100[] = 
{
	"bg_000_00_file2.dat",
	"bg_000_00_opt.dat",
	"bg_000_00_place2.dat",
	"bg_000_00_bone_pos.dat",
	"bg_000_p00.gmo",
	"floor_dummy_00.tga",
	"wall_dummy_00.tga"
};



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
	//DWORD address = *(DWORD*)(AbsoluteAddress);
	//const char *result = reinterpret_cast<char*>(address);

	*(DWORD*)AbsoluteAddress = replacementPtr;





	//Console::WriteLine(result);

	return true;
}
