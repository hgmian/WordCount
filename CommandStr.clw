; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCommandStrDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CommandStr.h"

ClassCount=3
Class1=CCommandStrApp
Class2=CCommandStrDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_COMMANDSTR_DIALOG

[CLS:CCommandStrApp]
Type=0
HeaderFile=CommandStr.h
ImplementationFile=CommandStr.cpp
Filter=N

[CLS:CCommandStrDlg]
Type=0
HeaderFile=CommandStrDlg.h
ImplementationFile=CommandStrDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCommandStrDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=CommandStrDlg.h
ImplementationFile=CommandStrDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COMMANDSTR_DIALOG]
Type=1
Class=CCommandStrDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_Command,edit,1350631552
Control6=IDC_LIST_OUT,listbox,1352728835

