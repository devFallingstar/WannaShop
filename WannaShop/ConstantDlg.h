#pragma once
#include "afxwin.h"


// CConstantDlg 대화 상자입니다.

class CConstantDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConstantDlg)

public:
	CConstantDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CConstantDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_Constant;
	afx_msg void OnEnChangeEdit1();
	CStatic m_Static1;
};
