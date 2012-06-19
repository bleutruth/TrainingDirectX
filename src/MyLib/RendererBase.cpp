//!
//!	@file	RendererBase.cpp
//!	@brief	ƒŒƒ“ƒ_ƒ‰Šî’ê
//!

#include "RendererBase.h"	//	ƒŒƒ“ƒ_ƒ‰Šî’ê

struct RendererBase::Impl{

	Impl(HWND, int, int);
	~Impl();

	HWND const hWnd;
	int const mScreenSizeW, mScreenSizeH;

};

RendererBase::Impl::Impl(HWND hWnd, int w, int h)
 :	hWnd(hWnd), mScreenSizeW(w), mScreenSizeH(h)
{
}

RendererBase::Impl::~Impl()
{
}

/*___________________________________________________________________________*/

RendererBase::RendererBase(HWND hWnd, int w, int h)
 :	mImpl(new Impl(hWnd, w, h))
{
}

RendererBase::~RendererBase()
{
}

HWND RendererBase::WindowHandle() const
{
	return mImpl->hWnd;
}

int RendererBase::ScreenSizeW() const
{
	return mImpl->mScreenSizeW;
}

int RendererBase::ScreenSizeH() const
{
	return mImpl->mScreenSizeH;
}

/*_________EOF_______________________________________________________________*/
