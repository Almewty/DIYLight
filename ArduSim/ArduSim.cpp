// ArduSim.cpp : Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include <cstdio>
#include "ArduSim.h"
#include <list>
#include "Compat.h"
#include "sketch.h"

std::list<byte> readList;
bool isSetup = false;

EXPORT void __stdcall write(byte *buf, int length)
{
	for (int i = 0; i < length; i++)
	{
		readList.push_back(buf[i]);
	}
	if (!isSetup)
	{
		setup();
		isSetup = true;
	}
	loop();
}

EXPORT int __stdcall read()
{
	if (readList.empty())
		return -1;
	byte data = readList.front();
	readList.pop_front();
	return data;
}

EXPORT bool __stdcall available()
{
	return !readList.empty();
}