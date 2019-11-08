#ifndef CONSOLE_H // include guard
#define CONSOLE_H

#include <Windows.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


class Console
{
	static string Format;
private:
	static HANDLE m_Screen;
public:
	
	static void Init();
	static const char* CombineString(const char* data);
	static void Write(char const* const _Format, ...);
	static void WriteLine(char const* const _Format, ...);
	static int AGConsole(const char *a1, ...);



};


#endif