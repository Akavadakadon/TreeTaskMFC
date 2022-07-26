
// TreeTask.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTreeTaskApp:
// See TreeTask.cpp for the implementation of this class
//

class CTreeTaskApp : public CWinApp
{
public:
	CTreeTaskApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton1();
};

extern CTreeTaskApp theApp;
