#pragma once
#include "afxdialogex.h"
#include <afxdb.h>

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
	int m_SGender;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();

//	생일을 받아올 컨트롤
	CTime m_time;
	CDateTimeCtrl m_datetime_date;

	CDatabase m_db; //데이터 베이스 연동
	CRecordset* m_prs;


	void InsertData(CString Signup_ID, CString Signup_PW, CString Signup_NICKNAME, CString Signup_NAME, CString Signup_GENDER, CString BRITHDAY, CString Signup_PHONE, int exist);
	int CheckDuplicatedID(CString Enter_ID);
	
	
	virtual void OnOK();
};
