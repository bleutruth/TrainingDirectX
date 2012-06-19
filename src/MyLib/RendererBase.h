//!
//!	@file	RendererBase.h
//!	@brief	ƒŒƒ“ƒ_ƒ‰Šî’ê
//!

#ifndef MYLIB_RENDERERBASE_H_20120620
#define MYLIB_RENDERERBASE_H_20120620

class RendererBase{

public:

	RendererBase(HWND hWnd, int w, int h);
	virtual ~RendererBase();

	virtual bool Init() = 0;

	HWND WindowHandle() const;
	int ScreenSizeW() const;
	int ScreenSizeH() const;

private:
	struct Impl;
	std::auto_ptr<Impl> mImpl;
};

#endif	//	MYLIB_RENDERERBASE_H_20120620
/*__________EOF______________________________________________________________*/
