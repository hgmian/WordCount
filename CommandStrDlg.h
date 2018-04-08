// CommandStrDlg.h : header file
//

#if !defined(AFX_COMMANDSTRDLG_H__DC7D7FA4_3F59_4425_9A7B_3197DBCBDD06__INCLUDED_)
#define AFX_COMMANDSTRDLG_H__DC7D7FA4_3F59_4425_9A7B_3197DBCBDD06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<iostream>  

/////////////////////////////////////////////////////////////////////////////
// CCommandStrDlg dialog

using namespace std;
struct Command
{
	bool _c; //�Ƿ�ͳ���ַ���
	bool _w; //�Ƿ�ͳ�Ƶ�����
	bool _l; //�Ƿ�ͳ������
	bool _o; //��������ָ��·��
	bool _s; //�ݹ鴦���ļ�·���µ������ļ�
	bool _e; //�Ƿ�����ͣ�ô�
	bool _a; //���ش����� ע���� ����
	
	char filePath[100];//�ļ�·��
	char outFile[100];//������·��
	char StopString[100]; //ͣ�ô�·��
};

class CCommandStrDlg : public CDialog
{
// Construction
public:
	CCommandStrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCommandStrDlg)
	enum { IDD = IDD_COMMANDSTR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommandStrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCommandStrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool SetCommand(string strCommand,Command &command);
	void OutPrintf(Command command);
	void OpenMyFile(CString strPath,Command command);
	int GetFindS(CString strtem);
	void ShowToWindow(int nCount,int nString,int nChar,Command command);
private:
	CListBox m_List;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDSTRDLG_H__DC7D7FA4_3F59_4425_9A7B_3197DBCBDD06__INCLUDED_)
