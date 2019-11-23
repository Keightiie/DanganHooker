#include "Hook.h"
#include "data.h"
#include "Scripting.h"

DWORD Hook::AbsolouteAddress(DWORD ExeAddress)
{
	return ExeAddress + BaseAddress + 0x1000;
}

bool Hook::InitiateHooks()
{
	for (int a = 0; a < 2; a++)
	{
		DetourInstructions(Data::Dangan2DetourInfo[a].AddressStart, Data::Dangan2DetourInfo[a].AddressEnd, Data::Dangan2DetourInfo[a].DetourFunction);
	}

	return true;
}

bool Hook::InitiateOpcodes()
{
	for (int a = 0; a < 77; a++)
	{
		Scripting::OperationFunctions[a] = ReadPointer(0x30B910 + (4 * a));
	}
	
	//Writes the new opcode count to the check for the array.
	WriteByte(0x7D2B8, Scripting::Cnt_opcodes);
	Scripting::ADDRESS_ReturnGetOpFunc = AbsolouteAddress(Data::Dangan2DetourInfo[1].AddressEnd);
	return true;
}

bool Hook::DetourInstructions(DWORD HookAddress, DWORD HookAddressEnd, void * NewFunction)
{
	int Length = HookAddressEnd - HookAddress;
	if (Length < 5)
	{
		Console::WriteLine("[ERROR] Length of instructions to replace was less then 5.");
		return false;
	}

	Console::WriteLine("[DEBUG] Instructions being replaced.");

	void * FuncToDetour = (void*)AbsolouteAddress(HookAddress);

	DWORD CurrentProtection;
	VirtualProtect(FuncToDetour, Length, PAGE_EXECUTE_READWRITE, &CurrentProtection);

	memset(FuncToDetour, 0x90, Length);

	DWORD RelativeAddress = ((DWORD)NewFunction - (DWORD)FuncToDetour) - 5;

	*(BYTE*)FuncToDetour = 0xE9;
	*(DWORD*)((DWORD)FuncToDetour + 1) = RelativeAddress;

	DWORD Temp;
	VirtualProtect(FuncToDetour, Length, CurrentProtection, &Temp);

	return true;
}

bool Hook::WritePointer(DWORD PointerAddress, DWORD Pointer)
{
	*(DWORD*)(AbsolouteAddress(PointerAddress)) = Pointer;
	return true;
}

bool Hook::WriteByte(DWORD ByteAddress, BYTE Byte)
{
	char * ByteToWriteTo = (char*)AbsolouteAddress(ByteAddress);
	DWORD curProtection;
	VirtualProtect(ByteToWriteTo, 1, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(ByteToWriteTo, Byte, 1);

	DWORD temp;
	VirtualProtect(ByteToWriteTo, 1, curProtection, &temp);


	return false;
}

void Hook::Init(int Game)
{

	if (!Hooked) 
	{
		BaseAddress = (DWORD)GetModuleHandleA("DR2_us.exe");

		if (InitiateHooks()) 
		{
			Console::WriteLine("[DEBUG] Instructions have been detoured!");
		}
		if (InitiateOpcodes()) 
		{
			Console::WriteLine("[DEBUG] Custom opcodes have been enabled!");
		}

		Hooked = true;
	}
	

}

DWORD Hook::ReadPointer(DWORD PointerAddress)
{
	return *(DWORD*)(AbsolouteAddress(PointerAddress));
}

