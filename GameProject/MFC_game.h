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

// MFC_game 폼 보기

class MFC_game : public CFormView
{
	DECLARE_DYNCREATE(MFC_game)

protected:
	MFC_game();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~MFC_game();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Play };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	//afx_msg void OnTimer(UINT_PTR nIDEvent);
	//afx_msg BOOL OnEraseBkgnd(CDC* pDC);
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
	int gover;

	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void Onmyeasy();
	afx_msg void Onmynomal();
	afx_msg void Onmyhard();
	afx_msg void OnmyHell();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnEnterSizeMove();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnPaint();
};


