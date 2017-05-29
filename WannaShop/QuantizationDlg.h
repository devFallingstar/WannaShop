#pragma once
#include "afxwin.h"


// CQuantizationDlg 대화 상자입니다.

class CQuantizationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CQuantizationDlg)

public:
	CQuantizationDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CQuantizationDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_QuantBit;
	afx_msg void OnEnChangeEdit1();
	CStatic m_Static1;
};
