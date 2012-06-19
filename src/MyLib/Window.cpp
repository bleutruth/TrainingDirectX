//!
//!	@file	Window.cpp
//!	@brief	ウィンドウ
//!

#include "Window.h"	//	ウィンドウ

struct Window::Impl{

	Impl(HINSTANCE hInstance, int, int);
	~Impl();

	bool Init();

	static LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

	HINSTANCE hInstance;
	HWND hWnd;

	int const mSizeW, mSizeH;

	static char const* const sWindowTitle;
	static WNDPROC sWndProc;

};

char const* const Window::Impl::sWindowTitle = "TrainingDirectX";
WNDPROC Window::Impl::sWndProc;

Window::Impl::Impl(HINSTANCE hInstance, int w, int h)
 :	hInstance(hInstance), hWnd(0), mSizeW(w), mSizeH(h)
{
}

Window::Impl::~Impl()
{
}

bool Window::Impl::Init()
{
	// Register the windows class
	WNDCLASS wnd;
	wnd.style = CS_DBLCLKS;
	wnd.lpfnWndProc = WndProc;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hInstance = hInstance;
	wnd.hIcon = 0;
	wnd.hCursor = LoadCursor( NULL, IDC_ARROW );
	wnd.hbrBackground = ( HBRUSH )GetStockObject( BLACK_BRUSH );
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = sWindowTitle;

	if(!RegisterClass(&wnd)){
		return false;
	}

	// クライアント領域のサイズから、ウィンドウ全体のサイズを計算
	RECT rc;
	SetRect(&rc, 0, 0, mSizeW, mSizeH);
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	//	ウィンドウ作成
	hWnd = CreateWindow(sWindowTitle, sWindowTitle, WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, 0,
                              0, hInstance, 0 );
	return (hWnd != 0);
}

LRESULT CALLBACK Window::Impl::WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch(uMsg){
	case WM_KEYDOWN:
		switch(wParam){

		// Escキーを受け取る
		case VK_ESCAPE:
			SendMessage(hWnd, WM_CLOSE, 0, 0);
			break;
		}
		break;

//	case WM_LBUTTONDOWN:
//	case WM_LBUTTONUP:
//	case WM_RBUTTONDOWN:
//	case WM_RBUTTONUP:
//	case WM_MOUSEMOVE:
//		if(sWndProc){
//			return sWndProc(hWnd, uMsg, wParam, lParam);
//		}
//		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		UnregisterClass(sWindowTitle, 0);
		break;

	case WM_DESTROY:
		PostQuitMessage( 0 );
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

/*___________________________________________________________________________*/

Window::Window(HINSTANCE hInstance, int w, int h)
 :	mImpl(new Impl(hInstance, w, h))
{
}

Window::~Window()
{
}

bool Window::Init()
{
	return mImpl->Init();
}

void Window::Show(int nCmdShow)
{
	ShowWindow(mImpl->hWnd, nCmdShow);
	UpdateWindow(mImpl->hWnd);
}

HWND Window::WindowHandle() const
{
	return mImpl->hWnd;
}

int Window::SizeW() const
{
	return mImpl->mSizeW;
}

int Window::SizeH() const
{
	return mImpl->mSizeH;
}

void Window::SetWndProc(WNDPROC proc)
{
	Impl::sWndProc = proc;
}

/*_________EOF_______________________________________________________________*/
