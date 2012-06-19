//!
//!	@file	AppBase.h
//!	@brief	App基底
//!

#ifndef MYLIB_APPBASE_H_20120619
#define MYLIB_APPBASE_H_20120619

class AppBase{

public:

	AppBase(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	virtual ~AppBase();

	//! アプリケーション実行
	bool Run();

private:

	virtual bool Init();

	struct Impl;
	std::auto_ptr<Impl> mImpl;
};

#endif	//	MYLIB_APPBASE_H_20120619
/*__________EOF______________________________________________________________*/
