//!
//!	@file	MyLib.cpp
//!	@brief	MyLib
//!

#include "MyLib.h"	//	MyLib

#include <crtdbg.h>

namespace MyLib{

void Init()
{
	// Enable run-time memory check for debug builds.
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
}

}	//	namespace MyLib

/*_________EOF_______________________________________________________________*/
