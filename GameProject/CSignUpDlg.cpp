// CSignUpDlg.cpp: 구현 파일
//

#include "pch.h"
#include "GameProject.h"
#include "afxdialogex.h"
#include "CSignUpDlg.h"


// CSignUpDlg 대화 상자

IMPLEMENT_DYNAMIC(CSignUpDlg, CDialogEx)

CSignUpDlg::CSignUpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SignUP, pParent)
{

}

CSignUpDlg::~CSignUpDlg()
{
}

void CSignUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSignUpDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSignUpDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSignUpDlg 메시지 처리기


void CSignUpDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString Signup_ID = _T(""); 
	CString Signup_PW = _T("");
	CString Signup_PW2 = _T("");
	CString Signup_NICKNAME = _T("");
	CString Signup_NAME = _T("");
	
	GetDlgItem(IDC_SID, Signup_ID);
	GetDlgItem(IDC_SID, Signup_ID);
	GetDlgItem(IDC_SID, Signup_ID);
	GetDlgItem(IDC_SID, Signup_ID);
	GetDlgItem(IDC_SID, Signup_ID);

	
	CDialogEx::OnOK();
}
