#pragma once

#include "GameProjectDoc.h"
#include "GameProjectView.h"
#include "afxdialogex.h"
#include <afxdb.h>
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

// CPlayFormView 폼 보기

class CPlayFormView : public CFormView
{
	DECLARE_DYNCREATE(CPlayFormView)

protected:
	CPlayFormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CPlayFormView();

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

	CDatabase m_db; //데이터 베이스 연동
	CRecordset* m_prs;
	CString m_name;

	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnDraw(CDC* /*pDC*/);
	//afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void KeyDown(MSG pMsg);
	void getNickname();
	afx_msg void OnmyEasy();
	afx_msg void OnmyNormal();
	afx_msg void OnmyHard();
	afx_msg void OnmyHell();

};


