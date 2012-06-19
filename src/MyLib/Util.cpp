//!
//!	@file	Util.cpp
//!	@brief	ユーティリティ
//!

#include "Util.h"	//	ユーティリティ

void DebugPrint(char const* format, ...)
{
	static char sBuf[256];	//!<1度に出力可能な文字数

	va_list args;
	va_start(args, format);
	vsnprintf(sBuf, sizeof(sBuf), format, args);
	OutputDebugString(sBuf);
	va_end(args);
}

/*_________EOF_______________________________________________________________*/
