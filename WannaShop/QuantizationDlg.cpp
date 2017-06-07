// QuantizationDlg.cpp : ±¸Çö ÆÄÀÏÀÔ´Ï´Ù.
//

#include "stdafx.h"
#include "WannaShop.h"
#include "QuantizationDlg.h"
#include "afxdialogex.h"


// CQuantizationDlg ´ëÈ­ »óÀÚÀÔ´Ï´Ù.

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
	m_Static1.SetWindowTextW(L"양자화값");
}


BEGIN_MESSAGE_MAP(CQuantizationDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CQuantizationDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CQuantizationDlg ¸Þ½ÃÁö Ã³¸®±âÀÔ´Ï´Ù.


void CQuantizationDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ÄÁÆ®·ÑÀÎ °æ¿ì, ÀÌ ÄÁÆ®·ÑÀº
	// CDialogEx::OnInitDialog() ÇÔ¼ö¸¦ ÀçÁöÁ¤ 
	//ÇÏ°í ¸¶½ºÅ©¿¡ OR ¿¬»êÇÏ¿© ¼³Á¤µÈ ENM_CHANGE ÇÃ·¡±×¸¦ ÁöÁ¤ÇÏ¿© CRichEditCtrl().SetEventMask()¸¦ È£ÃâÇÏÁö ¾ÊÀ¸¸é
	// ÀÌ ¾Ë¸² ¸Þ½ÃÁö¸¦ º¸³»Áö ¾Ê½À´Ï´Ù.

	// TODO:  ¿©±â¿¡ ÄÁÆ®·Ñ ¾Ë¸² Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
}
