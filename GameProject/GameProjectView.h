
// GameProjectView.h: CGameProjectView 클래스의 인터페이스
//

#pragma once
#include "PlayScreen.h"
#include "CSignupDlg.h"

class CGameProjectView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CGameProjectView() noexcept;
	DECLARE_DYNCREATE(CGameProjectView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_GAMEPROJECT_FORM };
#endif

// 특성입니다.
public:
	CGameProjectDoc* GetDocument() const;
	

// 작업입니다.
public:

	CSignUpDlg* m_SignupDlg;

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CGameProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSignup();
	afx_msg void OnBnClickedbtnLogin();
};

#ifndef _DEBUG  // GameProjectView.cpp의 디버그 버전
inline CGameProjectDoc* CGameProjectView::GetDocument() const
   { return reinterpret_cast<CGameProjectDoc*>(m_pDocument); }
#endif

