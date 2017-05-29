
// WannaShopView.cpp : CWannaShopView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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
END_MESSAGE_MAP()

// CWannaShopView 생성/소멸

CWannaShopView::CWannaShopView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CWannaShopView::~CWannaShopView()
{
}

BOOL CWannaShopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWannaShopView 그리기

void CWannaShopView::OnDraw(CDC* pDC)
{
	CWannaShopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int i, j;
	unsigned char R, G, B;
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
			R = G = B = pDoc->m_outputImage[i*pDoc->m_Re_width + j];
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CWannaShopView 인쇄

BOOL CWannaShopView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWannaShopView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWannaShopView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWannaShopView 진단

#ifdef _DEBUG
void CWannaShopView::AssertValid() const
{
	CView::AssertValid();
}

void CWannaShopView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWannaShopDoc* CWannaShopView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWannaShopDoc)));
	return (CWannaShopDoc*)m_pDocument;
}
#endif //_DEBUG




// CWannaShopView 메시지 처리기


void CWannaShopView::OnMenuDownSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling();

	Invalidate(TRUE);
}


void CWannaShopView::OnMenuUpSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling();

	Invalidate(TRUE);
}


void CWannaShopView::OnMenuQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization();

	Invalidate(TRUE);
}


void CWannaShopView::OnSumConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuSumConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnSubConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuSubConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnMulConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuMulConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnDivConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuDivConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuNegaConstant();

	Invalidate(TRUE);
}


void CWannaShopView::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuGammaCorrection();

	Invalidate(TRUE);
}


void CWannaShopView::OnBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWannaShopDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMenuBinarization();

	Invalidate(TRUE);
}

void CWannaShopView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CWannaShopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (point.x > 5 && point.x < pDoc->m_width
	&& point.y > 5 && point.y < pDoc->m_height)
	{
		CString str;
		int x=point.x, y=point.y;
		unsigned char pixelValue;
		pixelValue = pDoc->m_inputImage[x*y];

		str.Format(L"X 좌표 : %d Y좌표 : %d 픽셀 : %d", x, y, pixelValue);

		((CMainFrame*)AfxGetMainWnd())->GetStatusBar()->SetPaneText(0, str);
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CWannaShopView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CWannaShopDoc* pDoc = GetDocument();
	int avg, sum = 0, min=255, max=0;
	int width, height;
	int size;
	int i, j;
	CString contentsStr;

	width = pDoc->m_width;
	height = pDoc->m_height;
	size = width*height;

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
	contentsStr.Format(L"최소값은 %d입니다.\n최대값은 %d입니다.\n평균값은 %d입니다.", min, max, avg);
	MessageBox(contentsStr, L"값 알림", MB_ICONINFORMATION);

	CView::OnLButtonDown(nFlags, point);
}
