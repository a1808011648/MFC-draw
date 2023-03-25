
// MFC_TestQiniu2.h: MFC_TestQiniu2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CMFCTestQiniu2App:
// 有关此类的实现，请参阅 MFC_TestQiniu2.cpp
//

class CMFCTestQiniu2App : public CWinAppEx
{
public:
	CMFCTestQiniu2App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCTestQiniu2App theApp;
