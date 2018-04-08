// CommandStr.h : main header file for the COMMANDSTR application
//

#if !defined(AFX_COMMANDSTR_H__A5237821_666E_4C11_993C_80C2E71781EE__INCLUDED_)
#define AFX_COMMANDSTR_H__A5237821_666E_4C11_993C_80C2E71781EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCommandStrApp:
// See CommandStr.cpp for the implementation of this class
//

class CCommandStrApp : public CWinApp
{
public:
	CCommandStrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommandStrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCommandStrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDSTR_H__A5237821_666E_4C11_993C_80C2E71781EE__INCLUDED_)
