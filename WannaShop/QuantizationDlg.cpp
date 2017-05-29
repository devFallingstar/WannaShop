// QuantizationDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "WannaShop.h"
#include "QuantizationDlg.h"
#include "afxdialogex.h"


// CQuantizationDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CQuantizationDlg, CDialogEx)

CQuantizationDlg::CQuantizationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_QuantBit(0)
{

}

CQuantizationDlg::~CQuantizationDlg()
{
}

void CQuantizationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_QuantBit);
	DDV_MinMaxInt(pDX, m_QuantBit, 1, 32);
	DDX_Control(pDX, IDC_STATIC1, m_Static1);
	m_Static1.SetWindowTextW(L"단계");
}


BEGIN_MESSAGE_MAP(CQuantizationDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CQuantizationDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CQuantizationDlg 메시지 처리기입니다.


void CQuantizationDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
