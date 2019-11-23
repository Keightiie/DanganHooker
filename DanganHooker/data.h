#pragma once
#include <Windows.h>
#include "sound.h"


class Data 
{
public:
	struct DetourInfo
	{
		DWORD AddressStart;
		DWORD AddressEnd;
		void * DetourFunction;
		const char* DetourName;
	};

	static const DetourInfo Dangan2DetourInfo[];

};