// CommandStrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CommandStr.h"
#include "CommandStrDlg.h"
#include <sstream> 

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
// CCommandStrDlg dialog

CCommandStrDlg::CCommandStrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommandStrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCommandStrDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCommandStrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommandStrDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX,IDC_LIST_OUT,m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCommandStrDlg, CDialog)
	//{{AFX_MSG_MAP(CCommandStrDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommandStrDlg message handlers

BOOL CCommandStrDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCommandStrDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCommandStrDlg::OnPaint() 
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
HCURSOR CCommandStrDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCommandStrDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString strCommand;
	GetDlgItem(IDC_EDIT_Command)->GetWindowText(strCommand);
	Command _command;
	memset(&_command,0,sizeof(Command));//��ʼ�������нṹ��
	bool bRet = SetCommand(strCommand.GetBuffer(strCommand.GetLength()),_command);//������������,�������Ƿ����óɹ�
	if(bRet == false)
	{
		AfxMessageBox("�����ж�ȡʧ�ܣ�����������!");
		return;
	}
	OutPrintf(_command); //��ӡ���
}

bool CCommandStrDlg::SetCommand(string strCommand,Command &command)
{
	istringstream iss;
	iss.str(strCommand);
	string _str;
	bool bIsEmpty = false;
	while(iss>>_str)
	{//�������������������������
		bIsEmpty = true;
		if(strcmp(_str.c_str(),"-c") == 0)
			command._c = true;
		else if(strcmp(_str.c_str(),"-w") == 0)
			command._w = true;
		else if(strcmp(_str.c_str(),"-l") == 0)
			command._l = true;
		else if(strcmp(_str.c_str(),"-o") == 0)
		{
			command._o = true;
			iss>>_str;
			if(strcmp(_str.c_str(),"-c") == 0 ||
				strcmp(_str.c_str(),"-w") == 0 ||
				strcmp(_str.c_str(),"-l") == 0 ||
				strcmp(_str.c_str(),"-o") == 0 ||
				strcmp(_str.c_str(),"-s") == 0 ||
				strcmp(_str.c_str(),"-e") == 0 ||
				strcmp(_str.c_str(),"-a") == 0 ||
				_str.empty())
				return false;
			strcpy(command.outFile , _str.c_str());//�򿪵��ļ�ֻ�Ե�ǰ·����Ч
		}
		else if(strcmp(_str.c_str(),"-s") == 0)
			command._s = true;
		else if(strcmp(_str.c_str(),"-e") == 0)
		{
			command._e = true;
			iss>>_str;
			if(strcmp(_str.c_str(),"-c") == 0 ||
				strcmp(_str.c_str(),"-w") == 0 ||
				strcmp(_str.c_str(),"-l") == 0 ||
				strcmp(_str.c_str(),"-o") == 0 ||
				strcmp(_str.c_str(),"-s") == 0 ||
				strcmp(_str.c_str(),"-e") == 0 ||
				strcmp(_str.c_str(),"-a") == 0 ||
				_str.empty())
				return false;
			strcpy(command.StopString,_str.c_str());//�򿪵��ļ�ֻ�Ե�ǰ·����Ч
		}
		else if(strcmp(_str.c_str(),"-a") == 0)
			command._a = true;
		else if(!_str.empty())
			strcpy(command.filePath,_str.c_str()); //�򿪵��ļ�ֻ�Ե�ǰ·����Ч
		else
			return false;		
	}
	if(bIsEmpty)
		return true;
	else
		return false;

}

void CCommandStrDlg::OutPrintf(Command command)
{
	CString path;     
	GetModuleFileName(NULL,path.GetBufferSetLength(MAX_PATH+1),MAX_PATH);     
	path.ReleaseBuffer();     
	int pos = path.ReverseFind('\\');     
	path = path.Left(pos); 
	if(command.filePath[0] == '*')
	{
		//�ݹ鴦�����иú�׺���ļ�

	}
	else
	{
		//����ָ�����ļ�
		CString strPath;
		strPath = path + "\\" +command.filePath;
		OpenMyFile(strPath,command);

	}	
}

void CCommandStrDlg::OpenMyFile(CString strPath,Command command)
{
	//��ʱֻ�����������
	int nCount = 0;
	int nString = 0;
	int nChar = 0;
	CStdioFile myFile;
	if (myFile.Open(strPath,CFile::modeRead))
	{
		CString str;
		while(myFile.ReadString(str)) //���ж�ȡ
		{
			istringstream iss;
			iss.str(str.GetBuffer(str.GetLength()));
			string _str;
			while(iss>>_str)
			{
				CString strTem;
				strTem = _str.c_str();
				int nTmpString = GetFindS(strTem);
				nString += nTmpString;
				nString++;
				nChar += strTem.GetLength() - nTmpString; 
			}
			
			nCount++;
		}
	}
	myFile.Close();

	ShowToWindow(nCount,nString,nChar,command);
}

int CCommandStrDlg::GetFindS(CString strtem)
{
	int n = strtem.Find(',');
	if(n > 0)
	{
		CString str;
		str.Right(strtem.GetLength() - n);
		return GetFindS(str)+1;
	}
	else
		return 0;
}

void CCommandStrDlg::ShowToWindow(int nCount,int nString,int nChar,Command command)
{
	CStdioFile myFile;
	CString strPath;
	GetModuleFileName(NULL,strPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);     
	strPath.ReleaseBuffer();     
	int pos = strPath.ReverseFind('\\');     
	strPath = strPath.Left(pos); 
	if(command._o)
	{
		strPath = strPath + "\\" + command.outFile;	
	}
	else
	{
		strPath = strPath + "\\" + "result.txt";		
	}
	if(myFile.Open(strPath,CFile::modeCreate | CFile::modeReadWrite))
	{
		m_List.ResetContent();
		CString strFormat;
		if(command._c)
		{
			strFormat.Format("%s,�ַ���:%d",command.filePath,nChar);
			m_List.AddString(strFormat);
			strFormat = strFormat + "\n";
			myFile.WriteString(strFormat);
		}
		
		if(command._w)
		{
			strFormat.Format("%s,������:%d",command.filePath,nString);
			m_List.AddString(strFormat);
			strFormat = strFormat + "\n";
			myFile.WriteString(strFormat);
		}

		if(command._l)
		{
			strFormat.Format("%s,����:%d",command.filePath,nCount);
			m_List.AddString(strFormat);
			strFormat = strFormat + "\n";
			myFile.WriteString(strFormat);
		}
	}
	else
	{
		AfxMessageBox("����ļ�����ʧ��!");
	}

	myFile.Close();
}
