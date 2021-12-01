
// MFC_gaView.h: CMFCgaView 클래스의 인터페이스
//

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <string>
#include <atlimage.h>

using namespace std;
class CMFCgaView : public CView
{

protected: // serialization에서만 만들어집니다.
	CMFCgaView() noexcept;
	DECLARE_DYNCREATE(CMFCgaView)

// 특성입니다.
public:
	CMFCgaDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCgaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	int level;
	vector <CPoint> e;
	vector <int> er;
	vector <int> step_y;
	vector <CPoint> k;
	int start;
	int x;
	int y;
	int step;
	int m_winright;
	int m_winbottom;
	int count;
	afx_msg void Onmyeasy();
	afx_msg void Onmynomal();
	afx_msg void OnMyhard();
	afx_msg void OnMyhell();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int gover;
};

#ifndef _DEBUG  // MFC_gaView.cpp의 디버그 버전
inline CMFCgaDoc* CMFCgaView::GetDocument() const
   { return reinterpret_cast<CMFCgaDoc*>(m_pDocument); }
#endif

