#include "console.h"
#include "stdio.h"

HANDLE Console::m_Screen = NULL;


void Console::Init()
{
	AllocConsole();
	m_Screen = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Console::Write(char const* const _Format, ...)
{
	char buffer[256];
	va_list args;
	va_start(args, _Format);
	int result = vsnprintf(buffer, sizeof(buffer), _Format, args);
	
	DWORD Written;
	WriteConsole(m_Screen, buffer, sizeof(buffer), &Written, NULL);
}

void Console::WriteLine(char const* const _Format, ...)
{
	char buffer[256];
	va_list args;
	va_start(args, _Format);
	vsnprintf(buffer, sizeof(buffer), _Format, args);
	
	DWORD Written;
	WriteConsole(m_Screen, buffer, sizeof(buffer), &Written, NULL);
	WriteConsole(m_Screen, "\n", strlen("\n"), &Written, NULL);
}

int Console::AGConsole(const char *a1, ...)
{
	const int result = 1;
	char buffer[256];
	va_list args;
	va_start(args, a1);
	vsnprintf(buffer, sizeof(buffer),a1, args);
	
	WriteLine("[AGConsole] %s", buffer);

	return result;
}

