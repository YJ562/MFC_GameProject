#pragma once
#include "afxdialogex.h"


// CSignUpDlg 대화 상자

class CSignUpDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSignUpDlg)

public:
	CSignUpDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSignUpDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SignUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
