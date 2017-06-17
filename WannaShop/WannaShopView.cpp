
// WannaShopView.cpp : CWannaShopView Å¬·¡½ºÀÇ ±¸Çö
//

#include "stdafx.h"
// SHARED_HANDLERS´Â ¹Ì¸® º¸±â, Ãà¼ÒÆÇ ±×¸² ¹× °Ë»ö ÇÊÅÍ Ã³¸®±â¸¦ ±¸ÇöÇÏ´Â ATL ÇÁ·ÎÁ§Æ®¿¡¼­ Á¤ÀÇÇÒ ¼ö ÀÖÀ¸¸ç
// ÇØ´ç ÇÁ·ÎÁ§Æ®¿Í ¹®¼­ ÄÚµå¸¦ °øÀ¯ÇÏµµ·Ï ÇØ ÁÝ´Ï´Ù.
#ifndef SHARED_HANDLERS
#include "WannaShop.h"
#endif

#include "MainFrm.h"
#include "WannaShopDoc.h"
#include "WannaShopView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWannaShopView

IMPLEMENT_DYNCREATE(CWannaShopView, CView)

BEGIN_MESSAGE_MAP(CWannaShopView, CView)
	// Ç¥ÁØ ÀÎ¼â ¸í·ÉÀÔ´Ï´Ù.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_Menu_Down_Sampling, &CWannaShopView::OnMenuDownSampling)
	ON_COMMAND(ID_Menu_Up_Sampling, &CWannaShopView::OnMenuUpSampling)
	ON_COMMAND(ID_Menu_Quantization, &CWannaShopView::OnMenuQuantization)
	ON_COMMAND(ID_Sum_Constant, &CWannaShopView::OnSumConstant)
	ON_COMMAND(ID_Sub_Constant, &CWannaShopView::OnSubConstant)
	ON_COMMAND(ID_Mul_Constant, &CWannaShopView::OnMulConstant)
	ON_COMMAND(ID_Div_Constant, &CWannaShopView::OnDivConstant)
	ON_COMMAND(ID_Nega_Transform, &CWannaShopView::OnNegaTransform)
	ON_COMMAND(ID_Gamma_Correction, &CWannaShopView::OnGammaCorrection)
	ON_COMMAND(ID_Binarization, &CWannaShopView::OnBinarization)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_Histogram, &CWannaShopView::OnHistogram)
	ON_COMMAND(ID_Histo_Stretch, &CWannaShopView::OnHistoStretch)
	ON_COMMAND(ID_Histo_Equal, &CWannaShopView::OnHistoEqual)
	ON_COMMAND(ID_Embossing, &CWannaShopView::OnEmbossing)
	ON_COMMAND(ID_Blurr, &CWannaShopView::OnBlurr)
	ON_COMMAND(ID_Gaussian_Filter, &CWannaShopView::OnGaussianFilter)
	ON_COMMAND(ID_Sharpening, &CWannaShopView::OnSharpening)
	ON_COMMAND(ID_Median_Filter, &CWannaShopView::OnMedianFilter)
	ON_COMMAND(ID_Kuwahara_Filter, &CWannaShopView::OnKuwaharaFilter)
	ON_COMMAND(ID_Nearest, &CWannaShopView::OnNearest)
	ON_COMMAND(ID_Bilinear, &CWannaShopView::OnBilinear)
	ON_COMMAND(ID_Mean_Sub, &CWannaShopView::OnMeanSub)
	ON_COMMAND(ID_Median_Sub, &CWannaShopView::OnMedianSub)
	ON_COMMAND(ID_Translation, &CWannaShopView::OnTranslation)
	ON_COMMAND(ID_Mirror_Hor, &CWannaShopView::OnMirrorHor)
	ON_COMMAND(ID_RGB_to_HSI, &CWannaShopView::OnRgbtoHsi)
	ON_COMMAND(ID_HSI_to_RGB, &CWannaShopView::OnHsitoRgb)
	ON_COMMAND(ID_Light_Compensation, &CWannaShopView::OnLightCompensation)
	ON_COMMAND(ID_Color_Image_Segmentation, &CWannaShopView::OnColorImageSegmentation)
	ON_COMMAND(ID_Histo_Equal_Color, &CWannaShopView::OnHistoEqualColor)
END_MESSAGE_MAP()

// CWannaShopView »ý¼º/¼Ò¸ê

CWannaShopView::CWannaShopView()
{
	// TODO: ¿©±â¿¡ »ý¼º ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.

}

CWannaShopView::~CWannaShopView()
{
}

BOOL CWannaShopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs¸¦ ¼öÁ¤ÇÏ¿© ¿©±â¿¡¼­
	//  Window Å¬·¡½º ¶Ç´Â ½ºÅ¸ÀÏÀ» ¼öÁ¤ÇÕ´Ï´Ù.

	return CView::PreCreateWindow(cs);
}

// CWannaShopView ±×¸®±â

void CWannaShopView::OnDraw(CDC* pDC)
{
	CWannaShopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int i, j;
	unsigned char R, G, B;
	if (pDoc->m_isColor)
	{
		for (i = 0; i < pDoc->m_Scale; i++)
		{
			for (j = 0; j < pDoc->m_Scale; j++) {
				pDC->SetPixel(j + 5, i + 5, RGB(pDoc->m_OpenImg[i][j][0], pDoc->m_OpenImg[i][j][1], pDoc->m_OpenImg[i][j][2]));
			}
		}
	}
	else {
		for (i = 0; i < pDoc->m_height; i++)
		{
			for (j = 0; j < pDoc->m_width; j++) {
				R = G = B = pDoc->m_inputImage[i*pDoc->m_width + j];
				pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
			}
		}
		for (i = 0; i < pDoc->m_Re_height; i++)
		{
			for (j = 0; j < pDoc->m_Re_width; j++) {
				R = G = B = pDoc->m_outputImage[i*pDoc->m_width + j];
				pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
			}
		}
	}

	if (pDoc->m_isChangeToHSI)
	{
		for (i = 0; i < pDoc->m_Re_height; i++)
		{
			for (j = 0; j < pDoc->m_Re_width; j++) {
				R = G = B = pDoc->m_HImg[i*pDoc->m_Re_width + j];
				pDC->SetPixel(j + pDoc->m_Scale + 10, i + 5, RGB(R, G, B));
			}
		}
		for (i = 0; i < pDoc->m_Re_height; i++)
		{
			for (j = 0; j < pDoc->m_Re_width; j++) {
				R = G = B = pDoc->m_SImg[i*pDoc->m_Re_width + j];
				pDC->SetPixel(j + 5, i + pDoc->m_Scale + 10, RGB(R, G, B));
			}
		}
		for (i = 0; i < pDoc->m_Re_height; i++)
		{
			for (j = 0; j < pDoc->m_Re_width; j++) {
				R = G = B = pDoc->m_IImg[i*pDoc->m_Re_width + j];
				pDC->SetPixel(j + pDoc->m_Scale + 10, i + pDoc->m_Scale + 10, RGB(R, G, B));
			}
		}
	}
	else if (pDoc->m_isChangeToRGB) {
		for (i = 0; i < pDoc->m_Re_height; i++)
		{
			for (j = 0; j < pDoc->m_Re_width; j++) {
				pDC->SetPixel(j + pDoc->m_Scale + 10, i + 5, RGB(pDoc->m_ResultImg[i][j][0], pDoc->m_ResultImg[i][j][1], pDoc->m_ResultImg[i][j][2]));
			}
		}
	}
	else if (pDoc->m_isLightComp) {
		for (i = 0; i < pDoc->m_Re_height; i++)
		{
			for (j = 0; j < pDoc->m_Re_width; j++) {
				R = G = B = pDoc->m_outputImage[i*pDoc->m_Re_width + j];
				pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
			}
		}
	}
	else if (pDoc->m_isKMeansSeg) {
		for (i = 0; i < pDoc->m_Scale; i++)
		{
			for (j = 0; j < pDoc->m_Scale; j++) {
				pDC->SetPixel(j + pDoc->m_Scale + 10, i + 5, RGB(pDoc->m_ResultImg[i][j][0], pDoc->m_ResultImg[i][j][1], pDoc->m_ResultImg[i][j][2]));
			}
		}
	}
	// TODO: ¿©±â¿¡ ¿ø½Ã µ¥ÀÌÅÍ¿¡ ´ëÇÑ ±×¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
}

// CWannaShopView ÀÎ¼â
BOOL CWannaShopView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ±âº»ÀûÀÎ ÁØºñ
	return DoPreparePrinting(pInfo);
}

void CWannaShopView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ÀÎ¼âÇÏ±â Àü¿¡ Ãß°¡ ÃÊ±âÈ­ ÀÛ¾÷À» Ãß°¡ÇÕ´Ï´Ù.
}

void CWannaShopView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ÀÎ¼â ÈÄ Á¤¸® ÀÛ¾÷À» Ãß°¡ÇÕ´Ï´Ù.
}

// CWannaShopView Áø´Ü
#ifdef _DEBUG
void CWannaShopView::AssertValid() const
{
	CView::AssertValid();
}

void CWannaShopView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWannaShopDoc* CWannaShopView::GetDocument() const // µð¹ö±×µÇÁö ¾ÊÀº ¹öÀüÀº ÀÎ¶óÀÎÀ¸·Î ÁöÁ¤µË´Ï´Ù.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWannaShopDoc)));
	return (CWannaShopDoc*)m_pDocument;
}
#endif //_DEBUG

// CWannaShopView ¸Þ½ÃÁö Ã³¸®±â
void CWannaShopView::OnMenuDownSampling()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling();

	Invalidate(TRUE);
}

void CWannaShopView::OnMenuUpSampling()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling();

	Invalidate(TRUE);
}

void CWannaShopView::OnMenuQuantization()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization();

	Invalidate(TRUE);
}

void CWannaShopView::OnSumConstant()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuSumConstant();

	Invalidate(TRUE);
}

void CWannaShopView::OnSubConstant()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuSubConstant();

	Invalidate(TRUE);
}

void CWannaShopView::OnMulConstant()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuMulConstant();

	Invalidate(TRUE);
}

void CWannaShopView::OnDivConstant()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuDivConstant();

	Invalidate(TRUE);
}

void CWannaShopView::OnNegaTransform()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuNegaConstant();

	Invalidate(TRUE);
}

void CWannaShopView::OnGammaCorrection()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuGammaCorrection();

	Invalidate(TRUE);
}

void CWannaShopView::OnBinarization()
{
	// TODO: ¿©±â¿¡ ¸í·É Ã³¸®±â ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuBinarization();

	Invalidate(TRUE);
}

void CWannaShopView::OnHistogram()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuHistogram();

	Invalidate(TRUE);
}


void CWannaShopView::OnHistoStretch()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuHistoStretch();

	Invalidate(TRUE);
}


void CWannaShopView::OnHistoEqual()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuHistoEqual();

	Invalidate(TRUE);
}


void CWannaShopView::OnEmbossing()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuEmbossing();

	Invalidate(TRUE);
}


void CWannaShopView::OnBlurr()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuBlurr();

	Invalidate(TRUE);
}


void CWannaShopView::OnGaussianFilter()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuGaussianFilter();

	Invalidate(TRUE);
}


void CWannaShopView::OnSharpening()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuSharpening();

	Invalidate(TRUE);
}


void CWannaShopView::OnMedianFilter()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuMedianFilter();

	Invalidate(TRUE);
}


void CWannaShopView::OnKuwaharaFilter()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuKuwaharaFilter();

	Invalidate(TRUE);
}


void CWannaShopView::OnNearest()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuNearest();

	Invalidate(TRUE);
}


void CWannaShopView::OnBilinear()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuBilinear();

	Invalidate(TRUE);
}

void CWannaShopView::OnMedianSub()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuMedianSub();

	Invalidate(TRUE);
}

void CWannaShopView::OnMeanSub()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMeanSub();

	Invalidate(TRUE);
}


void CWannaShopView::OnTranslation()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuTranslation();

	Invalidate(TRUE);
}


void CWannaShopView::OnMirrorHor()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuMirrorHor();

	Invalidate(TRUE);
}

void CWannaShopView::OnRgbtoHsi()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuRgbToHsi();

	Invalidate(TRUE);
}

void CWannaShopView::OnHsitoRgb()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuHsiToRgb();

	Invalidate(TRUE);
}

void CWannaShopView::OnLightCompensation()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuLightCompensation();

	Invalidate(TRUE);
}

void CWannaShopView::OnColorImageSegmentation()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuColorImageSegmentation();

	Invalidate(TRUE);
}

void CWannaShopView::OnHistoEqualColor()
{
	// TODO: Add your command handler code here
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuHistoEqualColor();

	Invalidate(TRUE);
}


void CWannaShopView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ¿©±â¿¡ ¸Þ½ÃÁö Ã³¸®±â ÄÚµå¸¦ Ãß°¡ ¹×/¶Ç´Â ±âº»°ªÀ» È£ÃâÇÕ´Ï´Ù.
	CWannaShopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (point.x > 5 && point.x < pDoc->m_width
		&& point.y > 5 && point.y < pDoc->m_height)
	{
		CString str;
		int x = point.x, y = point.y;
		unsigned char pixelValue;
		pixelValue = pDoc->m_inputImage[x*y];

		str.Format(L"입력 이미지 : X 좌표값 : %d Y 좌표값 : %d 픽셀값 : %d", x, y, pixelValue);

		((CMainFrame*)AfxGetMainWnd())->GetStatusBar()->SetPaneText(0, str);
	}
	else if (point.x > (pDoc->m_width+10) && point.x < (pDoc->m_width) + 10 + (pDoc->m_Re_width)
		&& point.y > 5 && point.y < pDoc->m_Re_height)
	{
		CString str;
		int x = point.x, y = point.y;
		unsigned char pixelValue;
		pixelValue = pDoc->m_outputImage[x*y];

		str.Format(L"출력 이미지 : X 좌표값 : %d Y 좌표값 : %d 픽셀값 : %d", x-pDoc->m_Re_width, pDoc->m_Re_height-y, pixelValue);

		((CMainFrame*)AfxGetMainWnd())->GetStatusBar()->SetPaneText(0, str);
	}

	CView::OnMouseMove(nFlags, point);
}

void CWannaShopView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ¿©±â¿¡ ¸Þ½ÃÁö Ã³¸®±â ÄÚµå¸¦ Ãß°¡ ¹×/¶Ç´Â ±âº»°ªÀ» È£ÃâÇÕ´Ï´Ù.
	CWannaShopDoc* pDoc = GetDocument();
	int avg, sum = 0, min, max;
	int width, height;
	int size;
	int i, j;
	CString contentsStr;

	if (!(pDoc->m_isColor))
	{
		width = pDoc->m_width;
		height = pDoc->m_height;
		size = width*height;

		min = pDoc->m_inputImage[0];
		max = pDoc->m_inputImage[0];

		for (i = 0; i < size; i++)
		{
			int currentPixel = pDoc->m_inputImage[i];
			sum += currentPixel; /* sum for avg */

			if (currentPixel <= min) /* Check min */
			{
				min = currentPixel;
			}
			if (currentPixel >= max) /* Check max */
			{
				max = currentPixel;
			}
		}

		avg = sum / size;
		contentsStr.Format(L"입력 이미지 : 최소값은 %d\n최대값은 %d\n평균값은 %d입니다.", min, max, avg);
		MessageBox(contentsStr, L"값 알림", MB_ICONINFORMATION);
	}
	else {
		contentsStr.Format(L"색상 이미지에서는 지원되지 않습니다.");
		MessageBox(contentsStr, L"알림", MB_ICONINFORMATION);
	}

	CView::OnLButtonDown(nFlags, point);
}


