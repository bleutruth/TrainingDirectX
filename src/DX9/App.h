//!
//!	@file	App.h
//!	@brief	App
//!

#ifndef DX9_APP_H_20120619
#define DX9_APP_H_20120619

#include <AppBase.h>

class App : public AppBase{

public:

	App(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	virtual ~App();

	void Render();

private:

	bool Init();

	struct Impl;
	std::auto_ptr<Impl> mImpl;
};

#endif	//	DX9_APP_H_20120619
/*__________EOF______________________________________________________________*/
