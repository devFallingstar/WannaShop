#pragma once
#include "afxwin.h"


// CSamplingDlg 대화 상자입니다.

class CSamplingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSamplingDlg)

public:
	CSamplingDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSamplingDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_SamplingRate;
	CStatic m_Static1;
};
