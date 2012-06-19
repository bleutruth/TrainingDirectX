//!
//!	@file	Util.cpp
//!	@brief	���[�e�B���e�B
//!

#include "Util.h"	//	���[�e�B���e�B

void DebugPrint(char const* format, ...)
{
	static char sBuf[256];	//!<1�x�ɏo�͉\�ȕ�����

	va_list args;
	va_start(args, format);
	vsnprintf(sBuf, sizeof(sBuf), format, args);
	OutputDebugString(sBuf);
	va_end(args);
}

/*_________EOF_______________________________________________________________*/
