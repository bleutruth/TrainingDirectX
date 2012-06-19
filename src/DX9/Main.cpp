//!
//!	@file	Main.cpp
//!	@brief	WinMain
//!

#include <MyLib.h>
#include "App.h"

namespace{
std::auto_ptr<App> sApp;
}	//	namespace

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MyLib::Init();

	sApp.reset(new App(hInstance, hPrevInstance, lpCmdLine, nCmdShow));
	if(!sApp->Run()){
		return -1;
	}
	return 0;
}

/*_________EOF_______________________________________________________________*/
