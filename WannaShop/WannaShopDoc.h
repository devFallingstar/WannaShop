
// WannaShopDoc.h : CWannaShopDoc 클래스의 인터페이스
//


#pragma once
#include "Math.h"
#include "SamplingDlg.h"
#include "QuantizationDlg.h"
#include "ConstantDlg.h"
#include "PosDialog.h"

class CWannaShopDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CWannaShopDoc();
	DECLARE_DYNCREATE(CWannaShopDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CWannaShopDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	unsigned char* m_inputImage;
	unsigned char* m_outputImage;
	int m_size;
	int m_height;
	int m_width;

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	void OnDownSampling();
	unsigned char*OutputImage;
	int m_Re_width;
	int m_Re_height;
	int m_Re_size;
	double** m_tempImage;
	unsigned char m_OpenImg[256][256][3];
	unsigned char* m_HImg;
	unsigned char* m_SImg;
	unsigned char* m_IImg;
	bool m_isColor;
	bool m_isChangeToHSI;
	int m_Scale;
	void OnUpSampling();
	void OnQuantization();
	void OnMenuSumConstant();
	void OnMenuSubConstant();
	void OnMenuMulConstant();
	void OnMenuDivConstant();
	void OnMenuNegaConstant();
	void OnMenuGammaCorrection();
	void OnMenuBinarization();
	void OnMenuHistogram();
	void OnMenuHistoStretch();
	void OnMenuHistoEqual();
	void OnMenuEmbossing();
	double** OnMaskProcess(unsigned char *Target, double Mask[3][3]);
	double** OnScale(double **Target, int height, int width);
	double** Image2DMem(int height, int width);
	void OnMenuBlurr();
	void OnMenuGaussianFilter();
	void OnMenuSharpening();
	void OnMenuMedianFilter();
	void onBubbleSort(double*, int);
	void OnMenuKuwaharaFilter();
	int getKuwaharaValue(double*);
	void OnMenuNearest();
	void OnMenuBilinear();
	void OnMenuMedianSub();
	void OnMeanSub();
	void OnMenuTranslation();
	void OnMenuMirrorHor();
	void OnMenuRgbToHsi();
private:
	unsigned char Sol_S(unsigned char R, unsigned char G, unsigned char B);
	unsigned char Sol_H(unsigned char R, unsigned char G, unsigned char B);
	unsigned char Sol_I(unsigned char R, unsigned char G, unsigned char B);
	double MinDouble(double a, double b);
public:
	void OnMenuHsiToRgb();
	unsigned char m_ResultImg[256][256][3];
	bool m_isChangeToRGB;
	void OnMenuLightCompensation();
	bool m_isLightComp;
	void OnMenuColorImageSegmentation();
	boolean m_isKMeansSeg;
	void OnMenuHistoEqualColor();
};
