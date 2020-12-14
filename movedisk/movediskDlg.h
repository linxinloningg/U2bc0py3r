// movediskDlg.h : header file
//

#if !defined(AFX_MOVEDISKDLG_H__B2952E66_DA07_4CBE_BC1C_A7D0663BA870__INCLUDED_)
#define AFX_MOVEDISKDLG_H__B2952E66_DA07_4CBE_BC1C_A7D0663BA870__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMovediskDlg dialog

class CMovediskDlg : public CDialog
{
// Construction
public:
	CString finddsk();
	void filecopy(CString str);
	CMovediskDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMovediskDlg)
	enum { IDD = IDD_MOVEDISK_DIALOG };
	CString	m_path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMovediskDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMovediskDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void Onstrat();
	afx_msg void Onliulan();
	afx_msg void OnHIDE();
	afx_msg void OnButton5();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		public:
			BOOL setstrat;
			BOOL ait;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVEDISKDLG_H__B2952E66_DA07_4CBE_BC1C_A7D0663BA870__INCLUDED_)
