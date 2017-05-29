// SamplingDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "WannaShop.h"
#include "SamplingDlg.h"
#include "afxdialogex.h"


// CSamplingDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSamplingDlg, CDialogEx)

CSamplingDlg::CSamplingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_SamplingRate(0)
{

}

CSamplingDlg::~CSamplingDlg()
{
}

void CSamplingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_SamplingRate);
	DDV_MinMaxInt(pDX, m_SamplingRate, 1, 32);
	DDX_Control(pDX, IDC_STATIC1, m_Static1);
	m_Static1.SetWindowTextW(L"배율");
}


BEGIN_MESSAGE_MAP(CSamplingDlg, CDialogEx)
END_MESSAGE_MAP()


// CSamplingDlg 메시지 처리기입니다.
