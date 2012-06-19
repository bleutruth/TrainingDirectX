//!
//!	@file	Window.h
//!	@brief	ウィンドウ
//!

#ifndef MYLIB_WINDOW_H_20120407
#define MYLIB_WINDOW_H_20120407

class Window{

public:

	Window(HINSTANCE hInstance, int, int);
	virtual ~Window();

	bool Init();
	void Show(int nCmdShow);

	HWND WindowHandle() const;
	int SizeW() const;
	int SizeH() const;

	static void SetWndProc(WNDPROC);

private:
	struct Impl;
	std::auto_ptr<Impl> mImpl;
};

#endif	//	MYLIB_WINDOW_H_20120407
/*__________EOF______________________________________________________________*/
