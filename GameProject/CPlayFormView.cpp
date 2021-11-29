// CPlayFormView.cpp: 구현 파일
//

#include "pch.h"
#include "GameProject.h"
#include "CPlayFormView.h"
#include "MainFrm.h"


// CPlayFormView

IMPLEMENT_DYNCREATE(CPlayFormView, CFormView)

CPlayFormView::CPlayFormView()
	: CFormView(IDD_Play)
{
	
}

CPlayFormView::~CPlayFormView()
{
}

void CPlayFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPlayFormView, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CPlayFormView 진단

#ifdef _DEBUG
void CPlayFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPlayFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPlayFormView 메시지 처리기


void CPlayFormView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.


	
}


//void CPlayFormView::OnInitialUpdate()
//{
//	CFormView::OnInitialUpdate();
//
//	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
//	//GetParentFrame()->RecalcLayout();
//	//ResizeParentToFit();
//}
