// movedisk.h : main header file for the MOVEDISK application
//

#if !defined(AFX_MOVEDISK_H__9D0CF577_CB10_49AF_AA55_FBD42415E8C4__INCLUDED_)
#define AFX_MOVEDISK_H__9D0CF577_CB10_49AF_AA55_FBD42415E8C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMovediskApp:
// See movedisk.cpp for the implementation of this class
//

class CMovediskApp : public CWinApp
{
public:
	CMovediskApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMovediskApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMovediskApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVEDISK_H__9D0CF577_CB10_49AF_AA55_FBD42415E8C4__INCLUDED_)
