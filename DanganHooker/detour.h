#ifndef DETOUR_H // include guard
#define DETOUR_H

#include <Windows.h>
#include <fstream>
#include <iostream>


class Detour
{
public:
	static bool Hook(DWORD hookAddress, void * replacementFunc, int length);
	static DWORD GrabPointer(DWORD hookAddress);
	static DWORD GetExactAddress(DWORD relativeAddress);
	static bool HookStringPtr(DWORD hookAddress, DWORD replacementPtr);
	static bool WriteByte(DWORD ByteAdress, char NewByte);

};


#endif