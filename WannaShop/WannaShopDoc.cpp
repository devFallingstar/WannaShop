
// WannaShopDoc.cpp : CWannaShopDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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


// CWannaShopDoc 생성/소멸

CWannaShopDoc::CWannaShopDoc()
	: OutputImage(NULL)
	, m_Re_width(0)
	, m_Re_height(0)
	, m_Re_size(0)
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CWannaShopDoc::~CWannaShopDoc()
{
}

BOOL CWannaShopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}





// CWannaShopDoc serialization

void CWannaShopDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CWannaShopDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CWannaShopDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CWannaShopDoc 진단

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


// CWannaShopDoc 명령


BOOL CWannaShopDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	
	CFile File;
	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);

	if (File.GetLength() == 256 * 256) {
		m_height = 256;
		m_width = 256;
	} else if (File.GetLength() == 512 * 512) {
		m_height = 512;
		m_width = 512;
	} else if (File.GetLength() == 640 * 480) {
		m_height = 640;
		m_width = 480;
	}
	else {
		//AfxMessageBox("Not support");
		return 0;
	}

	m_size = m_height * m_width;
	m_inputImage = new unsigned char[m_size];

	for (int i = 0; i < m_size; i++) {
		m_inputImage[i] = 255;
	}
	File.Read(m_inputImage, m_size);
	File.Close();
	

	return TRUE;
}


BOOL CWannaShopDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CFile File;

	File.Open(lpszPathName, CFile::modeCreate | CFile::modeWrite);
	File.Write(m_outputImage, m_reSize);
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

		for ( i = 0; i < m_height; i++)
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
		
		for ( i = 0; i < m_size; i++)
		{
			for (j = 0; j < value; j++) {
				if (m_inputImage[i] >= (LEVEL/value)*j &&
					m_inputImage[i] < (LEVEL/value)*(j+1))
				{
					TEMP[i] = (double)(HIGH / value)*j; // Do Quantization
				}
			}
		}

		for ( i = 0; i < m_size; i++)
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

		for ( i = 0; i < m_size; i++)
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
