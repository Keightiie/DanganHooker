#include "console.h"

HANDLE Console::m_Screen = NULL;


const char* Console::CombineString(const char* data) 
{
	//string test = "";
	//va_list vaList;
	//va_start(vaList, data);
	//test += va_arg(vaList, char *);
	//test += va_arg(vaList, char *);
	//test += va_arg(vaList, char *);
	//test += va_arg(vaList, char *);
	//va_end(vaList);
	//return test.c_str;
}

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

	//result = dword_7C5D98;
	//if (!(dword_7C5D98 & 1))
	//{
	//	dword_7C5D98 |= 1u;
	//	result = sub_5552D0("Trace");
	//	dword_7C5D90 = 0;
	//}
	return result;
}

