
// TreeTaskDlg.h : header file
//

#pragma once
#include "MyCTreeCtrl.h"
#include "MyTreeVIew.h"


// CTreeTaskDlg dialog
class CTreeTaskDlg : public CDialogEx
{
// Construction
public:
	CTreeTaskDlg(CWnd* pParent = nullptr);	// standard constructor
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREETASK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	//MyCTreeCtrl* TREY;
	MyTreeVIew* TREY;
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);
};
