//!
//!	@file	AppBase.cpp
//!	@brief	AppŠî’ê
//!

#include "AppBase.h"	//	AppŠî’ê

#include "Window.h"

struct AppBase::Impl{

	Impl(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	~Impl();

	bool Init();
	void MainLoop();

	HINSTANCE hInstance, hPrevInstance;
	LPSTR lpCmdLine;
	int nCmdShow;

	std::auto_ptr<Window> mWindow;
};

AppBase::Impl::Impl(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
 :	hInstance(hInstance), hPrevInstance(hPrevInstance), lpCmdLine(lpCmdLine), nCmdShow(nCmdShow)
{
}

AppBase::Impl::~Impl()
{
}

bool AppBase::Impl::Init()
{
	static int const WINDOW_W = 800;
	static int const WINDOW_H = 600;
	mWindow.reset(new Window(hInstance, WINDOW_W, WINDOW_H));
	if(!mWindow->Init()){
		return false;
	}
	return true;
}

void AppBase::Impl::MainLoop()
{
	mWindow->Show(nCmdShow);

	HWND hWnd = mWindow->WindowHandle();

	bool bGotMsg;
	MSG msg;
	msg.message = WM_NULL;
	PeekMessage( &msg, NULL, 0U, 0U, PM_NOREMOVE );

	while( WM_QUIT != msg.message )
	{
		// Use PeekMessage() so we can use idle time to render the scene. 
		bGotMsg = ( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) != 0 );

		if( bGotMsg )
		{
			// Translate and dispatch the message
			if( hWnd == NULL ||
				0 == TranslateAccelerator( hWnd, 0, &msg ) )
			{
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			}
		}
		else{
//			mChangeScene = false;
//			Update();
//			Render();
		}
		Sleep(1);
	}
}

/*___________________________________________________________________________*/

AppBase::AppBase(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
 :	mImpl(new Impl(hInstance, hPrevInstance, lpCmdLine, nCmdShow))
{
}

AppBase::~AppBase()
{
}

bool AppBase::Run()
{
	if(!Init()){
		return false;
	}

	mImpl->MainLoop();
	return true;
}

bool AppBase::Init()
{
	if(!mImpl->Init()){
		return false;
	}
	return true;
}

/*_________EOF_______________________________________________________________*/
