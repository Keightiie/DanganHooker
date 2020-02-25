#pragma once
#include <Windows.h>
class Dr1Addresses {
public:
	const static DWORD FILE_PATH_START = 0xC46A0;
	const static DWORD FILE_PATH_END = 0xC4717;

	const static DWORD OPCODE_FUNCTION_ARRAY = 0x2943A8;
	const static DWORD OPCODE_SIZE_CMP_INSTRUCTION = 0x4D16F;
	const static DWORD OPCODE_START = 0x4D178;
	const static DWORD OPCODE_END = 0x4D17F;
};

class Dr2Addresses
{
public:
	const static DWORD VOICELINE_START = 0x332A0;
	const static DWORD VOICELINE_END = 0x333AE;

	const static DWORD OPCODE_SIZE_CMP_INSTRUCTION = 0x7d2b5;
	const static DWORD OPCODE_START = 0x7D2BE;
	const static DWORD OPCODE_END = 0x7D2C5;

	const static DWORD FILE_PATH_START = 0xEFCD0;
	const static DWORD FILE_PATH_END = 0xEFD47;

	const static DWORD OPCODE_FUNCTION_ARRAY = 0x30B910;
};

class CommonAddresses
{
public:
	static DWORD BaseAddress;
	static DWORD ReturnGetOpFunc;
};

static DWORD AbsoluteAddress(DWORD RelativeAddress)
{
	return CommonAddresses::BaseAddress + RelativeAddress + 0x1000;
}

static DWORD RelativeAddress(DWORD AbsoluteAddress)
{
	return AbsoluteAddress - CommonAddresses::BaseAddress - 0x1000;
}
