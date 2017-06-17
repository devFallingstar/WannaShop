
// WannaShopDoc.cpp : CWannaShopDoc Å¬·¡½ºÀÇ ±¸Çö
//

#include "stdafx.h"
// SHARED_HANDLERS´Â ¹Ì¸® º¸±â, Ãà¼ÒÆÇ ±×¸² ¹× °Ë»ö ÇÊÅÍ Ã³¸®±â¸¦ ±¸ÇöÇÏ´Â ATL ÇÁ·ÎÁ§Æ®¿¡¼­ Á¤ÀÇÇÒ ¼ö ÀÖÀ¸¸ç
// ÇØ´ç ÇÁ·ÎÁ§Æ®¿Í ¹®¼­ ÄÚµå¸¦ °øÀ¯ÇÏµµ·Ï ÇØ ÁÝ´Ï´Ù.
#ifndef SHARED_HANDLERS
#include "WannaShop.h"
#endif

#include "WannaShopDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWannaShopDoc

IMPLEMENT_DYNCREATE(CWannaShopDoc, CDocument)

BEGIN_MESSAGE_MAP(CWannaShopDoc, CDocument)
END_MESSAGE_MAP()


// CWannaShopDoc »ý¼º/¼Ò¸ê

CWannaShopDoc::CWannaShopDoc()
	: OutputImage(NULL)
	, m_Re_width(0)
	, m_Re_height(0)
	, m_Re_size(0)
	, m_tempImage(NULL)
	, m_isColor(false)
	, m_Scale(0)
	, m_HImg(0)
	, m_isChangeToHSI(false)
	, m_isChangeToRGB(false)
	, m_isLightComp(false)
	, m_isKMeansSeg(false)
{
	// TODO: ¿©±â¿¡ ÀÏÈ¸¼º »ý¼º ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.

}

CWannaShopDoc::~CWannaShopDoc()
{
}

BOOL CWannaShopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ¿©±â¿¡ ÀçÃÊ±âÈ­ ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	// SDI ¹®¼­´Â ÀÌ ¹®¼­¸¦ ´Ù½Ã »ç¿ëÇÕ´Ï´Ù.

	return TRUE;
}





// CWannaShopDoc serialization

void CWannaShopDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ¿©±â¿¡ ÀúÀå ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	}
	else
	{
		// TODO: ¿©±â¿¡ ·Îµù ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	}
}

#ifdef SHARED_HANDLERS

// Ãà¼ÒÆÇ ±×¸²À» Áö¿øÇÕ´Ï´Ù.
void CWannaShopDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ¹®¼­ÀÇ µ¥ÀÌÅÍ¸¦ ±×¸®·Á¸é ÀÌ ÄÚµå¸¦ ¼öÁ¤ÇÏ½Ê½Ã¿À.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// °Ë»ö Ã³¸®±â¸¦ Áö¿øÇÕ´Ï´Ù.
void CWannaShopDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ¹®¼­ÀÇ µ¥ÀÌÅÍ¿¡¼­ °Ë»ö ÄÜÅÙÃ÷¸¦ ¼³Á¤ÇÕ´Ï´Ù.
	// ÄÜÅÙÃ÷ ºÎºÐÀº ";"·Î ±¸ºÐµÇ¾î¾ß ÇÕ´Ï´Ù.

	// ¿¹: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CWannaShopDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CWannaShopDoc Áø´Ü

#ifdef _DEBUG
void CWannaShopDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWannaShopDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWannaShopDoc ¸í·É


BOOL CWannaShopDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  ¿©±â¿¡ Æ¯¼öÈ­µÈ ÀÛ¼º ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.

	CFile File;
	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);
	
	if (File.GetLength() == 256 * 256) {
		m_height = 256;
		m_width = 256;
	}
	else if (File.GetLength() == 512 * 512) {
		m_height = 512;
		m_width = 512;
	}
	else if (File.GetLength() == 640 * 480) {
		m_height = 640;
		m_width = 480;
	}
	else if (File.GetLength() == 256 * 256 * 3) {
		m_isColor = true;
		m_Scale = 256;
	}
	else if (File.GetLength() == 512 * 512 * 3) {
		m_isColor = true;
		m_Scale = 512;
	}
	else {
		return 0;
	}

	if (m_isColor)
	{
		/*
		m_OpenImg = new unsigned char**[m_Scale];
		for (int i = 0; i < m_Scale; i++)
		{
			m_OpenImg[i] = new unsigned char*[m_Scale];
			for (int j = 0; j < m_Scale; j++)
			{
				m_OpenImg[i][j] = new unsigned char[3];
			}
		}
		*/
		
		File.Read(m_OpenImg, m_Scale * m_Scale * 3);
		File.Close();
	}
	else {
		m_size = m_height * m_width;
		m_inputImage = new unsigned char[m_size];

		for (int i = 0; i < m_size; i++) {
			m_inputImage[i] = 255;
		}
		File.Read(m_inputImage, m_size);
		File.Close();
	}

	return TRUE;
}

BOOL CWannaShopDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: ¿©±â¿¡ Æ¯¼öÈ­µÈ ÄÚµå¸¦ Ãß°¡ ¹×/¶Ç´Â ±âº» Å¬·¡½º¸¦ È£ÃâÇÕ´Ï´Ù.
	CFile File;

	File.Open(lpszPathName, CFile::modeCreate | CFile::modeWrite);
	File.Write(m_outputImage, m_Re_size);
	File.Close();

	return true;
}

void CWannaShopDoc::OnDownSampling() {
	int i, j;
	CSamplingDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_Re_height = m_height / dlg.m_SamplingRate;
		m_Re_width = m_width / dlg.m_SamplingRate;
		m_Re_size = m_Re_height * m_Re_width;

		m_outputImage = new unsigned char[m_Re_size];
		for (i = 0; i < m_Re_height; i++)
		{
			for (j = 0; j < m_Re_width; j++) {
				m_outputImage[i*m_Re_width + j]
					= m_inputImage[(i*dlg.m_SamplingRate*m_width) + dlg.m_SamplingRate*j];
			}
		}
	}
}

void CWannaShopDoc::OnUpSampling()
{
	int i, j;
	CSamplingDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_Re_height = m_height * dlg.m_SamplingRate;
		m_Re_width = m_width * dlg.m_SamplingRate;
		m_Re_size = m_Re_height * m_Re_width;

		m_outputImage = new unsigned char[m_Re_size];

		for (i = 0; i < m_Re_size; i++)
		{
			m_outputImage[i] = 255;
		}

		for (i = 0; i < m_height; i++)
		{
			for (j = 0; j < m_width; j++) {
				m_outputImage[i*dlg.m_SamplingRate*m_Re_width +
					dlg.m_SamplingRate*j] = m_inputImage[(i*m_width) + j];
			}
		}
	}
}


void CWannaShopDoc::OnQuantization()
{
	CQuantizationDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		int i, j, value, LEVEL;
		double HIGH, *TEMP;

		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_outputImage = new unsigned char[m_Re_size];
		TEMP = new double[m_size];

		LEVEL = 256; //Quantization level of input image
		HIGH = 256.;

		value = (int)pow(2, dlg.m_QuantBit);

		for (i = 0; i < m_size; i++)
		{
			for (j = 0; j < value; j++) {
				if (m_inputImage[i] >= (LEVEL / value)*j &&
					m_inputImage[i] < (LEVEL / value)*(j + 1))
				{
					TEMP[i] = (double)(HIGH / value)*j; // Do Quantization
				}
			}
		}

		for (i = 0; i < m_size; i++)
		{
			m_outputImage[i] = (unsigned char)TEMP[i];
		}
	}
}


void CWannaShopDoc::OnMenuSumConstant()
{
	CConstantDlg dlg;

	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] + dlg.m_Constant >= 255)
			{
				m_outputImage[i] = 255;
			}
			else {
				m_outputImage[i] = (unsigned char)(m_inputImage[i] + dlg.m_Constant);
			}
		}
	}
}


void CWannaShopDoc::OnMenuSubConstant()
{
	CConstantDlg dlg;

	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] - dlg.m_Constant < 0)
			{
				m_outputImage[i] = 0;
			}
			else {
				m_outputImage[i] = (unsigned char)(m_inputImage[i] - dlg.m_Constant);
			}
		}
	}
}


void CWannaShopDoc::OnMenuMulConstant()
{
	CConstantDlg dlg;

	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] * dlg.m_Constant > 255)
			{
				m_outputImage[i] = 255;
			}
			else if (m_inputImage[i] * dlg.m_Constant < 0)
			{
				m_outputImage[i] = 0;
			}
			else {
				m_outputImage[i] = (unsigned char)(m_inputImage[i] * dlg.m_Constant);
			}
		}
	}
}


void CWannaShopDoc::OnMenuDivConstant()
{
	CConstantDlg dlg;

	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] / dlg.m_Constant > 255)
			{
				m_outputImage[i] = 255;
			}
			else if (m_inputImage[i] / dlg.m_Constant < 0)
			{
				m_outputImage[i] = 0;
			}
			else {
				m_outputImage[i] = (unsigned char)(m_inputImage[i] / dlg.m_Constant);
			}
		}
	}
}


void CWannaShopDoc::OnMenuNegaConstant()
{
	int i;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	for (i = 0; i < m_size; i++)
	{
		m_outputImage[i] = 255 - m_inputImage[i];
	}
}


void CWannaShopDoc::OnMenuGammaCorrection()
{
	CConstantDlg dlg;

	int i;
	double temp;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		unsigned char* LUT = new unsigned char[256];

		for (i = 0; i < 256; i++)
		{
			temp = pow(i, 1 / dlg.m_Constant);
			LUT[i] = temp > 255 ? 255 : temp;
		}

		for (i = 0; i < m_size; i++)
		{
			m_outputImage[i] = LUT[m_inputImage[i]];
		}
	}
}

void CWannaShopDoc::OnMenuBinarization()
{
	CConstantDlg dlg;

	int i;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK)
	{
		for (i = 0; i < m_size; i++) {
			if (m_inputImage[i] >= dlg.m_Constant)
			{
				m_outputImage[i] = 255;
			}
			else {
				m_outputImage[i] = 0;
			}
		}
	}
}


void CWannaShopDoc::OnMenuHistogram()
{
	int i, j;
	int MAX;
	int Histo[256];

	// Set histogram size
	m_Re_height = 256;
	m_Re_width = 256;
	m_Re_size = m_Re_height*m_Re_width;

	// init
	for (i = 0; i < 256; i++)
	{
		Histo[i] = 0;
	}

	for (i = 0; i < m_size; i++)
	{
		Histo[m_inputImage[i]]++;
	}

	// Generalazation
	MAX = Histo[0];
	for (i = 0; i < 256; i++)
	{
		if (Histo[i] > MAX) {
			MAX = Histo[i];
		}
	}
	for (i = 0; i < 256; i++)
	{
		Histo[i] = (int)(Histo[i] * 255 / MAX);
	}

	m_outputImage = new unsigned char[m_Re_size + (258 * 20)];
	for (i = 0; i < m_Re_size; i++)
	{
		m_outputImage[i] = 255;
	}
	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < Histo[i]; j++) {
			m_outputImage[m_Re_width*(m_Re_height - j - 1) + i] = 0;
		}
	}
	for (i = m_Re_height; i < m_Re_height + 5; i++)
	{
		for (j = 0; j < 256; j++) {
			m_outputImage[m_Re_height*i + j] = 255;
		}
	}
	for (i = m_Re_height + 5; i < m_Re_height + 20; i++)
	{
		for (j = 0; j < 256; j++) {
			m_outputImage[m_Re_height*i + j] = j;
		}
	}

	m_Re_height = m_Re_height + 20;
	m_Re_size = m_Re_width * m_Re_height;
}


void CWannaShopDoc::OnMenuHistoStretch()
{
	int i;
	unsigned char LOW, HIGH, MAX, MIN;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0;
	HIGH = 255;

	MIN = m_inputImage[0];
	MAX = m_inputImage[0];

	for (i = 0; i < m_size; i++)
	{
		if (m_inputImage[i] < MIN) {
			MIN = m_inputImage[i];
		}
	}
	for (i = 0; i < m_size; i++)
	{
		if (m_inputImage[i] > MAX) {
			MAX = m_inputImage[i];
		}
	}
	m_outputImage = new unsigned char[m_Re_size];
	for (i = 0; i < m_size; i++)
	{
		m_outputImage[i] = (unsigned char)((m_inputImage[i] - MIN)*HIGH / (MAX - MIN));
	}
}


void CWannaShopDoc::OnMenuHistoEqual()
{
	int i, value;
	unsigned char LOW, HIGH, Temp;
	double SUM = 0.0;
	double* m_HIST = new double[256];
	double* m_Sum_Of_HIST = new double[256];

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0; HIGH = 255;
	// 초기화 
	for (i = 0; i < 256; i++)
		m_HIST[i] = LOW;

	// 빈도 수 조사 
	for (i = 0; i < m_size; i++) {
		value = (int)m_inputImage[i];
		m_HIST[value]++;
	}

	// 누적 히스토그램 생성 
	for (i = 0; i < 256; i++) {
		SUM += m_HIST[i];
		m_Sum_Of_HIST[i] = SUM;
	}

	m_outputImage = new unsigned char[m_Re_size];

	// 입력 영상을 평활화된 영상으로 출력 
	for (i = 0; i < m_size; i++) {
		Temp = m_inputImage[i];
		m_outputImage[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
	}
}


void CWannaShopDoc::OnMenuEmbossing()
{
	int i, j;
	double EmboMask[3][3] = { {-1,0,0},{0,0,0},{0,0,1} };
	//Choose mask
	//double EmboMask[3][3] = { {0,0,0},{0,1,0},{0,0,0} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height*m_Re_width;
	m_outputImage = new unsigned char[m_Re_size];
	m_tempImage = OnMaskProcess(m_inputImage, EmboMask);
	//회선 처리
	printf("%ld", m_tempImage[1][2]);
	printf("%ld", m_tempImage[1][3]);
	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255)
			{
				m_tempImage[i][j] = 255;
			}
			else if (m_tempImage[i][j] < 0)
			{
				m_tempImage[i][j] = 0;
			}
		}
	}

	//m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);
	// 정규화 함수를 사용할 때

	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++) {
			m_outputImage[i*m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


double** CWannaShopDoc::OnMaskProcess(unsigned char *Target, double Mask[3][3])
{
	int i, j, n, m;
	double **tempInputImage, **tempOutputImage, S = 0.0;
	tempInputImage = Image2DMem(m_height + 2, m_width + 2);
	tempOutputImage = Image2DMem(m_height, m_width);
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			tempInputImage[i + 1][j + 1] = (double)Target[i * m_width + j];
		}
	}
	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			for (n = 0; n < 3; n++) {
				for (m = 0; m < 3; m++) {
					S += Mask[n][m] * tempInputImage[i + n][j + m];
				}
			}  tempOutputImage[i][j] = S;
			S = 0.0;
		}
	}

	return tempOutputImage; // 결과 값 반환
}


double** CWannaShopDoc::OnScale(double **Target, int height, int width)
{
	int i, j; double min, max;
	min = max = Target[0][0];
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (Target[i][j] <= min) min = Target[i][j];
		}
	}
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (Target[i][j] >= max) max = Target[i][j];
		}
	}
	max = max - min;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			Target[i][j] = (Target[i][j] - min) * (255. / max);
		}
	}
	return Target;
}

double** CWannaShopDoc::Image2DMem(int height, int width)
{
	double** temp;
	int i, j;
	temp = new double *[height];
	for (i = 0; i < height; i++) {
		temp[i] = new double[width];
	}
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			temp[i][j] = 0.0;
		}
	}

	return temp;
}


void CWannaShopDoc::OnMenuBlurr()
{
	int i, j;
	double BlurrMask[3][3] = { {1. / 9., 1. / 9., 1. / 9.},{ 1. / 9., 1. / 9., 1. / 9. },{ 1. / 9., 1. / 9., 1. / 9. } };

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];
	m_tempImage = OnMaskProcess(m_inputImage, BlurrMask);

	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			if (m_tempImage[i][j] > 255) {
				m_tempImage[i][j] = 255;
			}
			if (m_tempImage[i][j] < 0)
			{
				m_tempImage[i][j] = 0;
			}
		}
	}
	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			m_outputImage[i*m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CWannaShopDoc::OnMenuGaussianFilter()
{
	int i, j;
	double GaussianMask[3][3] = { {1. / 16., 1. / 8., 1. / 16.},{ 1. / 8., 1. / 4., 1. / 8. },{ 1. / 16., 1. / 8., 1. / 16. } };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height*m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_inputImage, GaussianMask);

	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			if (m_tempImage[i][j] > 255) {
				m_tempImage[i][j] = 255;
			}
			if (m_tempImage[i][j] < 0)
			{
				m_tempImage[i][j] = 0;
			}
		}
	}
	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			m_outputImage[i*m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CWannaShopDoc::OnMenuSharpening()
{
	int i, j;
	double SharpeningMask[3][3] = { {-1.,-1.,-1.}, {-1.,9.,-1.}, {-1.,-1. - 1.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height*m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_inputImage, SharpeningMask);

	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			if (m_tempImage[i][j] > 255) {
				m_tempImage[i][j] = 255;
			}
			if (m_tempImage[i][j] < 0)
			{
				m_tempImage[i][j] = 0;
			}
		}
	}
	for (i = 0; i < m_Re_height; i++)
	{
		for (j = 0; j < m_Re_width; j++)
		{
			m_outputImage[i*m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CWannaShopDoc::OnMenuMedianFilter()
{
	int i, j, n, m, index = 0;
	double **tempInputImage, Mask[9];

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	tempInputImage = Image2DMem(m_height + 2, m_width + 2);

	for ( i = 0; i < m_height; i++)
	{
		for (j = 0; j < m_width; j++) {
			tempInputImage[i + 1][j + 1] = (double)m_inputImage[i*m_width + j];
		}
	}

	for ( i = 0; i < m_height; i++){
		for (j = 0; j < m_width; j++) {
			for ( n = 0; n < 3; n++){
				for (m = 0; m < 3; m++) {
					Mask[n * 3 + m] = tempInputImage[i + n][j + m];
				}
			}
			onBubbleSort(Mask, 9);
			m_outputImage[index] = (unsigned char)Mask[4];
			index++;
		}
	}
}

void CWannaShopDoc::OnMenuKuwaharaFilter()
{
	int i, j, n, m, index = 0, tmpIdx = 0;
	int kValue;
	double **tempInputImage, Mask[25];

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];

	tempInputImage = Image2DMem(m_height + 4, m_width + 4);

	for (i = 0; i < m_height; i++)
	{
		for (j = 0; j < m_width; j++) {
			tempInputImage[i + 1][j + 1] = (double)m_inputImage[i*m_width + j];
		}
	}

	for (i = 0; i < m_height; i++) {
		for (j = 0; j < m_width; j++) {
			for (n = 0; n < 5; n++) {
				for (m = 0; m < 5; m++) {
					Mask[n * 5 + m] = tempInputImage[i + n][j + m];
				}
			}
			kValue = getKuwaharaValue(Mask);
			m_outputImage[index] = kValue;
			index++;
		}
	}
}

int CWannaShopDoc::getKuwaharaValue(double *Matrix)
{
	int i, j, k=0, l=0;
	int min=0;
	double space[4][9];
	double sum[4] = { 0, }, avg[4] = { 1, }, devPowSum[4] = { 0, }, var[4] = { 0. };

	/* Divide space for 4 space */
	for ( i = 0; i <= 10; i += 5)
	{
		for ( j = 0; j < 3; j++)
		{
			space[0][l] = Matrix[i+j];
			l++;
		}
	}

	k++;
	l = 0;
	for (i = 10; i <= 20; i += 5)
	{
		for (j = 0; j < 3; j++)
		{
			space[1][l] = Matrix[i + j];
			l++;
		}
	}
	k++;
	l = 0;
	for (i = 2; i <= 12; i += 5)
	{
		for (j = 0; j < 3; j++)
		{
			space[2][l] = Matrix[i + j];
			l++;
		}
	}
	k++;
	l = 0;
	for (i = 12; i <= 22; i += 5)
	{
		for (j = 0; j < 3; j++)
		{
			space[3][l] = Matrix[i + j];
			l++;
		}
	}

	/* Get sum of all bit for each spaces */
	for ( i = 0; i < 4; i++)
	{
		for (j = 0; j < 9; j++) {
			sum[i] += space[i][j];
		}
	}

	/* Get average of each spaces */
	for ( i = 0; i < 4; i++)
	{
		avg[i] = sum[i] / 9;
	}

	/* Get sum of pow for deviation of each spaces */
	for ( i = 0; i < 4; i++)
	{
		for ( j = 0; j < 9; j++)
		{
			devPowSum[i] += pow((space[i][j] - avg[i]), 2);
		}
	}

	/* Get variant of each spaces */
	for ( i = 0; i < 4; i++)
	{
		var[i] += devPowSum[i] / 9;
	}

	/* Get minimum index with variants */
	for ( i = 0; i < 4; i++)
	{
		if (var[i] <= var[min]) {
			min = i;
		}
	}

	return avg[min];
}

void CWannaShopDoc::onBubbleSort(double *numbers, int size)
{
	int i = 0, j = 0, temp = 0;
	for (j = 0; j<size; j++)
	{
		for (i = 0; i<size - 1; i++)
		{
			if (numbers[i]>numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
			}
		}
	}
}

void CWannaShopDoc::OnMenuNearest()
{
	int i, j;
	CConstantDlg dlg;
	int ZoomRate;
	double **tempArray;

	if (dlg.DoModal() == IDOK)
	{
		ZoomRate = dlg.m_Constant;

		m_Re_height = int(ZoomRate*m_height);
		m_Re_width = int(ZoomRate*m_width);
		m_Re_size = m_Re_height*m_Re_width;

		m_tempImage = Image2DMem(m_height, m_width);
		tempArray = Image2DMem(m_Re_height, m_Re_width);

		m_outputImage = new unsigned char[m_Re_size];

		for ( i = 0; i < m_height; i++)
		{
			for (j = 0; j < m_width; j++) {
				m_tempImage[i][j] = (double)m_inputImage[i*m_width + j];
			}
		}
		for (i = 0; i < m_Re_height; i++)
		{
			for (j = 0; j < m_Re_width; j++) {
				tempArray[i][j] = m_tempImage[i / ZoomRate][j / ZoomRate];
			}
		}

		for ( i = 0; i < m_Re_height; i++)
		{
			for (j = 0; j < m_Re_width; j++) {
				m_outputImage[i*m_Re_width + j] = (unsigned char)tempArray[i][j];
			}
		}
	}
}

void CWannaShopDoc::OnMenuBilinear()
{
	int i, j;
	CConstantDlg dlg;
	int ZoomRate;

	int point, i_H, i_W;
	unsigned char newValue;
	double r_H, r_W, s_H, s_W;
	double C1, C2, C3, C4;

	if (dlg.DoModal() == IDOK)
	{
		ZoomRate = dlg.m_Constant;

		m_Re_height = int(ZoomRate*m_height);
		m_Re_width = int(ZoomRate*m_width);
		m_Re_size = m_Re_height*m_Re_width;

		m_tempImage = Image2DMem(m_height, m_width);

		m_outputImage = new unsigned char[m_Re_size];

		for ( i = 0; i < m_height; i++)
		{
			for (j = 0; j < m_width; j++) {
				m_tempImage[i][j] = (double)m_inputImage[i*m_width + j];
			}
		}

		for ( i = 0; i < m_Re_height; i++)
		{
			for (j = 0; j < m_Re_width; j++) {
				r_H = i / ZoomRate;
				r_W = j / ZoomRate;

				i_H = (int)floor(r_H);
				i_W = (int)floor(r_W);

				s_H = r_H - i_H;
				s_W = r_W - i_W;

				if (i_H < 0 || i_H >= (m_height-1) || 
					i_W < 0 || i_W >= (m_width-1))
				{
					point = i*m_Re_width + j;
					m_outputImage[point] = 255;
				}
				else {
					C1 = (double)m_tempImage[i_H][i_W];
					C2 = (double)m_tempImage[i_H][i_W+1];
					C3 = (double)m_tempImage[i_H+1][i_W+1];
					C4 = (double)m_tempImage[i_H+1][i_W];

					newValue = (unsigned char)(C1*(1 - s_H)*(1 - s_W) + C2*s_W*(1 - s_H) + C3*s_W*s_H + C4*(1 - s_W)*s_H);
					point = i*m_Re_width + j;
					m_outputImage[point] = newValue;
				}
			}
		}
	}
}

void CWannaShopDoc::OnMenuMedianSub()
{
	int i, j, n, m, M, index = 0;
	double *Mask, Value;
	CConstantDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		M = dlg.m_Constant;
		Mask = new double[M*M];

		m_Re_height = (m_height + 1) / M;
		m_Re_width = (m_width + 1) / M;
		m_Re_size = m_Re_height * m_Re_width;

		m_outputImage = new unsigned char[m_Re_size];
		m_tempImage = Image2DMem(m_height + 1, m_width + 1);

		for (i = 0; i < m_height; i++)
		{
			for (j = 0; j < m_width; j++) {
				m_tempImage[i][j] = (double)m_inputImage[i*m_width + j];
			}
		}

		for (i = 0; i < m_height - 1; i = i + M)
		{
			for (j = 0; j < m_width - 1; j = j + M) {
				for (n = 0; n < M; n++)
				{
					for (m = 0; m < M; m++)
					{
						Mask[n*M + m] = m_tempImage[i + n][j + m];
					}
				}
				onBubbleSort(Mask, M*M);
				Value = Mask[(int)(M*M / 2)];
				m_outputImage[index] = (unsigned char)Value;
				index++;
			}
		}
	}
}

void CWannaShopDoc::OnMeanSub()
{
	int i, j, n, m, M, index = 0, k;
	double *Mask, Value, Sum = 0.0;
	CConstantDlg dlg;
	
	if (dlg.DoModal() == IDOK)
	{
		M = dlg.m_Constant;

		Mask = new double[M*M];

		m_Re_height = (m_height + 1) / M;
		m_Re_width = (m_width + 1) / M;
		m_Re_size = m_Re_height * m_Re_width;

		m_outputImage = new unsigned char[m_Re_size];
		m_tempImage = Image2DMem(m_height + 1, m_width + 1);

		for (i = 0; i < m_height; i++)
		{
			for (j = 0; j < m_width; j++) {
				m_tempImage[i][j] = (double)m_inputImage[i*m_width + j];
			}
		}

		for (i = 0; i < m_height - 1; i = i + M)
		{
			for (j = 0; j < m_width - 1; j = j + M) {
				for (n = 0; n < M; n++)
				{
					for (m = 0; m < M; m++)
					{
						Mask[n*M + m] = m_tempImage[i + n][j + m];
					}
				}
				for ( k = 0; k < M*M; k++)
				{
					Sum = Sum + Mask[k];
				}
				Value = (Sum / (M*M));
				m_outputImage[index] = (unsigned char)Value;
				index++;
				Sum = 0.0;
			}
		}
	}
}

void CWannaShopDoc::OnMenuTranslation()
{
	int i, j;
	int h_pos, w_pos;
	double **tempArray;
	CPosDialog dlg;

	if (dlg.DoModal() == IDOK)
	{
		h_pos = dlg.m_hPos;
		w_pos = dlg.m_wPos;

		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_outputImage = new unsigned char[m_Re_size];

		m_tempImage = Image2DMem(m_height, m_width);
		tempArray = Image2DMem(m_Re_height, m_Re_width);

		for ( i = 0; i < m_height; i++)
		{
			for (j = 0; j < m_width; j++) {
				m_tempImage[i][j] = (double)m_inputImage[i*m_width + j];
			}
		}

		for ( i = 0; i < m_height - h_pos; i++)
		{
			for ( j = 0; j < m_width - w_pos; j++)
			{
				tempArray[i + h_pos][j + w_pos] = m_tempImage[i][j];
			}
		}

		for ( i = 0; i < m_Re_height; i++)
		{
			for (j = 0; j < m_Re_width; j++) {
				m_outputImage[i*m_Re_width + j] = (unsigned char)tempArray[i][j];
			}
		}

		delete[] m_tempImage;
		delete[] tempArray;
	}
}


void CWannaShopDoc::OnMenuMirrorHor()
{
}


void CWannaShopDoc::OnMenuRgbToHsi()
{
	int i,j,k;
	m_Re_height = m_Scale;
	m_Re_width = m_Scale;
	m_Re_size = m_Re_height * m_Re_width;

	m_outputImage = new unsigned char[m_Re_size];
	m_HImg = new unsigned char[m_Re_size];
	m_SImg = new unsigned char[m_Re_size];
	m_IImg = new unsigned char[m_Re_size];

	for (i = 0; i < m_Scale; i++)
	{
		for ( j = 0; j < m_Scale; j++)
		{
			m_HImg[(i*m_Scale) + j] = Sol_H(m_OpenImg[i][j][0], m_OpenImg[i][j][1], m_OpenImg[i][j][2]);
			m_SImg[(i*m_Scale) + j] = Sol_S(m_OpenImg[i][j][0], m_OpenImg[i][j][1], m_OpenImg[i][j][2]);
			m_IImg[(i*m_Scale) + j] = Sol_I(m_OpenImg[i][j][0], m_OpenImg[i][j][1], m_OpenImg[i][j][2]);
		}
	}
	m_isChangeToHSI = true;
	m_isChangeToRGB = false;
}

unsigned char CWannaShopDoc::Sol_H(unsigned char R, unsigned char G, unsigned char B)
{
	double angle;
	double RR, GG, BB;

	if (R==G && G==B)
	{
		return 0;
	}

	RR = R / 255.;
	GG = G / 255.;
	BB = B / 255.;

	angle = ((RR - 0.5*GG) - (0.5*BB)) / (float)sqrt((RR - GG)*(RR - GG) + (RR - BB)*(GG - BB));
	angle = acos(angle);
	angle *= 57.29577951;

	if (B>G)
	{
		angle = 360.0 - angle;
	}

	return (unsigned char)((angle / 360) * 255.0);
}

unsigned char CWannaShopDoc::Sol_S(unsigned char R, unsigned char G, unsigned char B)
{
	double minc;
	double RR, GG, BB;

	RR = R / 255.;
	GG = G / 255.;
	BB = B / 255.;
	if (RR+GG+BB == 0)
	{
		return 0;
	}
	minc = MinDouble(RR, GG);
	minc = MinDouble(minc, BB);

	return (unsigned char)((1.0-(3.0/(RR+GG+BB))*minc)*255.0);
}

unsigned char CWannaShopDoc::Sol_I(unsigned char R, unsigned char G, unsigned char B)
{
	double RR, GG, BB;

	RR = R / 255.;
	GG = G / 255.;
	BB = B / 255.;

	if (RR+GG+BB == 0)
	{
		return 100;
	}

	return (unsigned char)((RR+GG+BB)/3*255.0);
}

void CWannaShopDoc::OnMenuHsiToRgb()
{
	int i, j;
	double H, S, I;
	double RR, GG, BB;
	double angle1, angle2;

	for ( i = 0; i < m_Scale; i++)
	{
		for ( j = 0; j < m_Scale; j++)
		{
			H = (double)((m_HImg[(i*m_Scale) + j] / 255.0) * 360.0);
			S = (double)(m_SImg[(i*m_Scale) + j] / 255.0);
			I = (double)(m_IImg[(i*m_Scale) + j] / 255.0);

			if (I <= 0.0)
			{
				m_ResultImg[i][j][0] = 0;
				m_ResultImg[i][j][1] = 0;
				m_ResultImg[i][j][2] = 0;
				continue;
			}

			if (I >= 1.0)
			{
				m_ResultImg[i][j][0] = 255;
				m_ResultImg[i][j][1] = 255;
				m_ResultImg[i][j][2] = 255;
				continue;
			}

			if (H<0.0)
			{
				H += 360;
			}

			if (H <= 120.0)
			{
				angle1 = H*0.017453293;
				angle2 = (60 - H)*0.017453293;
				BB = (1.0 - S) / 3.0;
				RR = (1.0 + (S*cos(angle1) / cos(angle2))) / 3.0;
				GG = 1.0 - RR - BB;
			}
			else if (120 < H && H <= 240.0)
			{
				H = H - 120.0;
				angle1 = H * 0.017453293;
				angle2 = (60 - H)*0.017453293;
				RR = (1.0 - S) / 3.0;
				GG = (1.0 + (S*cos(angle1) / cos(angle2))) / 3.0;
				BB = 1.0 - RR - GG;
			}
			else
			{
				H = H - 240.0;
				angle1 = H*0.017453293;
				angle2 = (68 - H)*0.017453293;
				GG = (1.0 - 5) / 3.0;
				BB = (1.0 + (S*cos(angle1) / cos(angle2))) / 3.0;
				RR = 1.0 - GG - BB;
			}

			RR = RR*255.0*3.0*I;
			GG = GG*255.0*3.0*I;
			BB = BB*255.0*3.0*I;

			if (RR > 255) {
				RR = 255;
			}
			if (GG > 255)
			{
				GG = 255;
			}
			if (BB > 255)
			{
				BB = 255;
			}

			m_ResultImg[i][j][0] = unsigned char(RR);
			m_ResultImg[i][j][1] = unsigned char(GG);
			m_ResultImg[i][j][2] = unsigned char(BB);
		}
	}
	m_isChangeToHSI = false;
	m_isChangeToRGB = true;
}

void CWannaShopDoc::OnMenuLightCompensation()
{
	double Y[256][256];
	double minY = 9999999.0;
	double maxY = -0000000.0;

	for (int i = 0; i < m_Scale; i++)
	{
		for (int j = 0; j < m_Scale; j++)
		{
			Y[i][j] = 0.299*m_OpenImg[i][j][0] +
				0.587*m_OpenImg[i][j][1] + 0.144*m_OpenImg[i][j][2];
		}
	}

	for (int i = 0; i < m_Scale; i++)
	{
		for (int j = 0; j < m_Scale; j++)
		{
			if (Y[i][j] > maxY) {
				maxY = Y[i][j];
			}
			if (Y[i][j] < minY) {
				minY = Y[i][j];
			}
		}
	}

	double Yr = maxY - (maxY - minY) * 0.05;
	int Yr_count = 0;

	for (int i = 0; i < m_Scale; i++)
	{
		for (int j = 0; j < m_Scale; j++)
		{
			if (Y[i][j] > Yr) 
			{
				Yr_count++;
			}
		}
	}

	double Rave, Gave, Bave;
	Rave = Gave = Bave = 0.0;

	for (int i = 0; i < m_Scale; i++)
	{
		for (int j = 0; j < m_Scale; j++)
		{
			if (Y[i][j] > Yr)
			{
				Rave += (double)m_OpenImg[i][j][0] / Yr_count;
				Gave += (double)m_OpenImg[i][j][1] / Yr_count;
				Bave += (double)m_OpenImg[i][j][2] / Yr_count;
			}
		}
	}

	double Rratio = 255.0 / Rave;
	double Gratio = 255.0 / Gave;
	double Bratio = 255.0 / Bave;

	double R, G, B;

	for (int i = 0; i < m_Scale; i++)
	{
		for (int j = 0; j < m_Scale; j++)
		{
			R = m_OpenImg[i][j][0] * Rratio;
			G = m_OpenImg[i][j][1] * Gratio;
			B = m_OpenImg[i][j][2] * Bratio;
			if (R >= 255.0)
			{
				R = 255.0;
			}
			if (G >= 255.0)
			{
				G = 255.0;
			}
			if (B >= 255.0)
			{
				B = 255.0;
			}
			m_ResultImg[i][j][0] = (unsigned char)R;
			m_ResultImg[i][j][1] = (unsigned char)G;
			m_ResultImg[i][j][2] = (unsigned char)B;
		}
	}
	m_isLightComp = true;
}

void CWannaShopDoc::OnMenuColorImageSegmentation()
{
	static const int K = 15;
	int loop = 1;
	int cluster[256][256] = { K + 1, };
	int preCluster;
	double sum[K][3];
	double center[K][3];
	double min = 9999999999.9;
	int minIndex;
	int number[K];
	double dist;

	for (int k = 0; k < K; k++) {
		int x, y;
		x = rand() % 256;
		y = rand() % 256;
		center[k][0] = (double)m_OpenImg[x][y][0];
		center[k][1] = (double)m_OpenImg[x][y][1];
		center[k][2] = (double)m_OpenImg[x][y][2];
	}

	while (loop == 1)
	{
		loop = 0;
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 256; j++) {
				preCluster = cluster[i][j];
				min = 9999999999.9;
				for (int k = 0; k < K; k++) {
					dist =
						sqrt(pow(m_OpenImg[i][j][0] - center[k][0], 2.0) +
							pow(m_OpenImg[i][j][1] - center[k][1], 2.0) +
							pow(m_OpenImg[i][j][2] - center[k][2], 2.0));
					if (dist < min) {
						min = dist;
						minIndex = k;
					}
				}
				cluster[i][j] = minIndex;
				if (cluster[i][j] != preCluster) loop = 1;
			}
		}

		for (int k = 0; k < K; k++) {
			sum[k][0] = 0.0; sum[k][1] = 0.0; sum[k][2] = 0.0;
			number[k] = 0;
		}

		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 256; j++) {
				sum[cluster[i][j]][0] += m_OpenImg[i][j][0];
				sum[cluster[i][j]][1] += m_OpenImg[i][j][1];
				sum[cluster[i][j]][2] += m_OpenImg[i][j][2];
				number[cluster[i][j]]++;
			}
		}

		for (int k = 0; k < K; k++) {
			center[k][0] = sum[k][0] / number[k];
			center[k][1] = sum[k][1] / number[k];
			center[k][2] = sum[k][2] / number[k];
		}
	}

	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			m_ResultImg[i][j][0] = (unsigned char)center[cluster[i][j]][0];
			m_ResultImg[i][j][1] = (unsigned char)center[cluster[i][j]][1];
			m_ResultImg[i][j][2] = (unsigned char)center[cluster[i][j]][2];
		}
	}

	m_isKMeansSeg = true;
}

void CWannaShopDoc::OnMenuHistoEqualColor()
{
	OnMenuRgbToHsi();

	int i, value;
	unsigned char LOW, HIGH, Temp;
	double SUM = 0.0;
	double* m_HIST = new double[256];
	double* m_Sum_Of_HIST = new double[256];

	m_Re_height = m_Scale;
	m_Re_width = m_Scale;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0; HIGH = 255;
	// 초기화 
	for (i = 0; i < 256; i++)
		m_HIST[i] = LOW;

	// 빈도 수 조사 
	for (i = 0; i < m_size; i++) {
		value = (int)m_IImg[i];
		m_HIST[value]++;
	}

	// 누적 히스토그램 생성 
	for (i = 0; i < 256; i++) {
		SUM += m_HIST[i];
		m_Sum_Of_HIST[i] = SUM;
	}

	m_outputImage = new unsigned char[m_Re_size];

	// 입력 영상을 평활화된 영상으로 출력 
	for (i = 0; i < m_size; i++) {
		Temp = m_IImg[i];
		m_IImg[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
		
	}

	m_isLightComp = true;

	m_outputIma

	//OnMenuHsiToRgb();
}

double CWannaShopDoc::MinDouble(double a, double b)
{
	return (a < b) ? a : b;
}