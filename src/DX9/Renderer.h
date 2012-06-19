//!
//!	@file	Renderer.h
//!	@brief	ƒŒƒ“ƒ_ƒ‰
//!

#ifndef DX9_RENDERER_H_20120620
#define DX9_RENDERER_H_20120620

#include <RendererBase.h>

class Renderer : public RendererBase{

public:

	Renderer(HWND hWnd, int w, int h);
	virtual ~Renderer();

	virtual bool Init();

private:
	struct Impl;
	std::auto_ptr<Impl> mImpl;
};

#endif	//	DX9_RENDERER_H_20120620
/*__________EOF______________________________________________________________*/
