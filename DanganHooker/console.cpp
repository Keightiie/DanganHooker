#include "console.h"

HANDLE Console::m_Screen = NULL;


void Console::Init()
{
	AllocConsole();
	m_Screen = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Console::Write(char const* const _Format, ...)
{
	DWORD Written;
	WriteConsole(m_Screen, _Format, strlen(_Format), &Written, NULL);
}

void Console::WriteLine(char const* const _Format, ...)
{
	DWORD Written;
	WriteConsole(m_Screen, _Format, strlen(_Format), &Written, NULL);
	WriteConsole(m_Screen, "\n", strlen("\n"), &Written, NULL);

}

int Console::AGConsole(const char *a1, ...)
{
	int result = 1;
	WriteLine(a1);

	return result;
}

