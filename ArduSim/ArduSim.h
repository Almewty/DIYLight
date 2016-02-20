#pragma once

#include "stdafx.h"

#define EXPORT __declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

	EXPORT void __stdcall write(BYTE *buf, int length);
	EXPORT int __stdcall read();
	EXPORT bool __stdcall available();

#ifdef __cplusplus
}
#endif
