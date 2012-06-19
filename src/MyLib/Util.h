//!
//!	@file	Util.h
//!	@brief	ユーティリティ
//!

#ifndef MYLIB_UTIL_H_20120408
#define MYLIB_UTIL_H_20120408

#define SIZE_OF_ARRAY(ary)		(sizeof(ary) / sizeof(ary[0]))

template<typename T> T Clamp(T val, T min, T max){ return std::min<T>(std::max<T>(val, min), max); }

#define SAFE_DELETE(p)			{ delete (p); (p) = 0; }
#define SAFE_DELETE_ARRAY(p)	{ delete[] (p); (p) = 0; }
#define SAFE_RELEASE(p)			{ if(p){ (p)->Release(); (p) = 0; } }

#define STATIC_ASSERT(cond)		extern int static_assert_[cond ? 1 : -1]

//!
//! 数学関係
//!

float const PI = 3.1415926536f;

inline float Deg2Rad(float d){ return (d * 2 * PI / 360.0f); }
inline float Rad2Deg(float rad){ return ((rad * 360.0f) / (2 * PI)); }

//!
//! デバッグ出力
//!
#ifndef NDEBUG
#define LOG	DebugPrint
#else
#define LOG(...)
#endif

void DebugPrint(char const* format, ...);

#endif	//	MYLIB_UTIL_H_20120408
/*__________EOF______________________________________________________________*/
