#pragma once
#include <Windows.h>

class Scripting
{
public:

	static const int Cnt_opcodes = 0x100;
	static DWORD OperationFunctions[];
	static DWORD ADDRESS_ReturnGetOpFunc;

	static void GetOperationFunction();
	static void LoadCustomOpcodes();

	//
	static const DWORD ScriptPointerAddresses[];
	static const DWORD ScriptPositionAddresses[];
	static BYTE ReadByte();


	//opcode Functions
	static void TEST_CustomOpcode();
};

