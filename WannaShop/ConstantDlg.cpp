// ConstantDlg.cpp : ±¸Çö ÆÄÀÏÀÔ´Ï´Ù.
//

#include "stdafx.h"
#include "WannaShop.h"
#include "ConstantDlg.h"
#include "afxdialogex.h"


// CConstantDlg ´ëÈ­ »óÀÚÀÔ´Ï´Ù.

IMPLEMENT_DYNAMIC(CConstantDlg, CDialogEx)

CConstantDlg::CConstantDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_Constant(0)
{

}

CConstantDlg::~CConstantDlg()
{
}

void CConstantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Constant);
	DDV_MinMaxDouble(pDX, m_Constant, 0, 255);
	DDX_Control(pDX, IDC_STATIC1, m_Static1);
	m_Static1.SetWindowTextW(L"상수값");
}


BEGIN_MESSAGE_MAP(CConstantDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CConstantDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CConstantDlg ¸Þ½ÃÁö Ã³¸®±âÀÔ´Ï´Ù.


void CConstantDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ÄÁÆ®·ÑÀÎ °æ¿ì, ÀÌ ÄÁÆ®·ÑÀº
	// CDialogEx::OnInitDialog() ÇÔ¼ö¸¦ ÀçÁöÁ¤ 
	//ÇÏ°í ¸¶½ºÅ©¿¡ OR ¿¬»êÇÏ¿© ¼³Á¤µÈ ENM_CHANGE ÇÃ·¡±×¸¦ ÁöÁ¤ÇÏ¿© CRichEditCtrl().SetEventMask()¸¦ È£ÃâÇÏÁö ¾ÊÀ¸¸é
	// ÀÌ ¾Ë¸² ¸Þ½ÃÁö¸¦ º¸³»Áö ¾Ê½À´Ï´Ù.

	// TODO:  ¿©±â¿¡ ÄÁÆ®·Ñ ¾Ë¸² Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
}
