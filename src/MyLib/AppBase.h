//!
//!	@file	AppBase.h
//!	@brief	App���
//!

#ifndef MYLIB_APPBASE_H_20120619
#define MYLIB_APPBASE_H_20120619

class Window;

class AppBase{

public:

	AppBase(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	virtual ~AppBase();

	//! �A�v���P�[�V�������s
	bool Run();
	virtual void Render(){}

	Window* Window() const;

protected:

	virtual bool Init();

private:

	struct Impl;
	std::auto_ptr<Impl> mImpl;
};

#endif	//	MYLIB_APPBASE_H_20120619
/*__________EOF______________________________________________________________*/
