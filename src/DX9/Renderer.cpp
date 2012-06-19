//!
//!	@file	Renderer.cpp
//!	@brief	ƒŒƒ“ƒ_ƒ‰
//!

#include "Renderer.h"	//	ƒŒƒ“ƒ_ƒ‰

struct Renderer::Impl{

	Impl();
	~Impl();

	bool Init(HWND hWnd, int w, int h);
	bool CreateDevice(HWND hWnd, int w, int h);
	bool CreateFont();

	LPDIRECT3D9 mD3D;
	LPDIRECT3DDEVICE9 mDev;
	LPD3DXFONT mFont;
};

Renderer::Impl::Impl()
 :	mD3D(0), mDev(0), mFont(0)
{
}

Renderer::Impl::~Impl()
{
	SAFE_RELEASE(mFont);
	SAFE_RELEASE(mDev);
	SAFE_RELEASE(mD3D);
}

bool Renderer::Impl::Init(HWND hWnd, int w, int h)
{
	mD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if(!mD3D){
		return false;
	}

	if(!CreateDevice(hWnd, w, h)){
		return false;
	}
	if(!CreateFont()){
		return false;
	}
	return true;
}

bool Renderer::Impl::CreateDevice(HWND hWnd, int w, int h)
{
	D3DPRESENT_PARAMETERS pp;
	memset(&pp, 0, sizeof(pp));

	pp.BackBufferWidth = w;
	pp.BackBufferHeight = h;
	pp.BackBufferFormat = D3DFMT_X8R8G8B8;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.Windowed = TRUE;
	pp.EnableAutoDepthStencil = TRUE;
	pp.AutoDepthStencilFormat = D3DFMT_D24X8;
	pp.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;

	if(FAILED(mD3D->CreateDevice(0, D3DDEVTYPE_HAL, hWnd,
						D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
						&pp, &mDev))){
		return false;
	}
	return true;
}

bool Renderer::Impl::CreateFont()
{
	if(FAILED(D3DXCreateFont(mDev, 16, 0, FW_NORMAL, 1, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, "‚l‚r ‚oƒSƒVƒbƒN", &mFont))){
		return false;
	}
	return true;
}

/*___________________________________________________________________________*/

Renderer::Renderer(HWND hWnd, int w, int h)
 :	RendererBase(hWnd, w, h),
	mImpl(new Impl)
{
}

Renderer::~Renderer()
{
}

bool Renderer::Init()
{
	return mImpl->Init(WindowHandle(), ScreenSizeW(), ScreenSizeH());
}

/*_________EOF_______________________________________________________________*/
