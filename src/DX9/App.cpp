//!
//!	@file	App.cpp
//!	@brief	App
//!

#include "App.h"	//	App

#include <Window.h>
#include "Renderer.h"

struct App::Impl{

	Impl();
	~Impl();

	bool Init(class Window const*);

	std::auto_ptr<Renderer> mRenderer;
};

App::Impl::Impl()
{
}

App::Impl::~Impl()
{
}

bool App::Impl::Init(class Window const* window)
{
	mRenderer.reset(new Renderer(window->WindowHandle(), window->SizeW(), window->SizeH()));
	if(!mRenderer->Init()){
		return false;
	}
	return true;
}

/*___________________________________________________________________________*/

App::App(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
 :	AppBase(hInstance, hPrevInstance, lpCmdLine, nCmdShow),
	mImpl(new Impl)
{
}

App::~App()
{
}

bool App::Init()
{
	if(!AppBase::Init()){
		return false;
	}
	if(!mImpl->Init(Window())){
		return false;
	}
	return true;
}

/*_________EOF_______________________________________________________________*/
