	
// TreeTaskDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "TreeTask.h"
#include "TreeTaskDlg.h"
#include "afxdialogex.h"

#include "TFileReader.h"
#include "TNode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTreeTaskDlg dialog



CTreeTaskDlg::CTreeTaskDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TREETASK_DIALOG, pParent)
{
	TREY = new MyTreeVIew();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeTaskDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, *TREY); 
}

BEGIN_MESSAGE_MAP(CTreeTaskDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTreeTaskDlg::OnBnClickedButton1)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, &CTreeTaskDlg::OnDblclkTree1)
END_MESSAGE_MAP()


// CTreeTaskDlg message handlers

BOOL CTreeTaskDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//TREY = TREY1.GetTreeCtrl();

	//auto res = TREY.InsertItem(TNode(0,-1,_T("asd"),1, _T("asd")));
	//auto res1 = TREY.InsertItem(TNode(1, 0, _T("asd1"), 1, _T("asd1")));

	//HTREEITEM hWA = TREY.InsertItem(_T("Washington"),NULL);

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CTreeTaskDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTreeTaskDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTreeTaskDlg::OnBnClickedButton1()
{
	wchar_t buffer[MAX_PATH+1];
	GetModuleFileName(NULL, buffer, _MAX_PATH);
	CFileDialog fileDialog(TRUE, (LPCTSTR)NULL, buffer);

	int result = fileDialog.DoModal();
	if (result != IDOK)
		return;
	CString pathString = fileDialog.GetPathName();

	auto res= TFileReader::ReadNodesFromFile(pathString);
	if (!res)
		return;
	for (TNode newNode : *res)
	{
		TREY->InsertItem(newNode);
	}
}




void CTreeTaskDlg::OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	TNode selected = TREY->GetSelectedItem();

	if(selected.Status())
	int msgboxID = MessageBox(selected.Message(),
		selected.Caption());
	*pResult = 1; // Disable expanding on dclick
	return;
}

