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
	, m_SGender(0)
{

}

CSignUpDlg::~CSignUpDlg()
{
}

void CSignUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_RADIO1, m_SGender);
	DDX_Radio(pDX, IDC_RADIO1, m_SGender);
}


BEGIN_MESSAGE_MAP(CSignUpDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSignUpDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &CSignUpDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CSignUpDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CSignUpDlg 메시지 처리기


void CSignUpDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString Signup_ID = _T(""); 
	CString Signup_PW = _T("");
	CString Signup_PW2 = _T(""); //아이디 확인
	CString Signup_NICKNAME = _T("");
	CString Signup_NAME = _T("");
	
	CString Signup_GENDER = _T("");


	//회원가입 다이얼로그에서 입력을 받아옴.
	GetDlgItemText(IDC_SID, Signup_ID);
	GetDlgItemText(IDC_SPW, Signup_PW);
	GetDlgItemText(IDC_PCHECK, Signup_PW2);
	GetDlgItemText(IDC_NICKNAME, Signup_NICKNAME);
	GetDlgItemText(IDC_NAME, Signup_NAME);

	UpdateData(true);

	switch (m_SGender) {

	case 0:  Signup_GENDER = "남성"; break;
	case 1:  Signup_GENDER = "여성"; 
	}

	CString test =  Signup_ID + "\n" + Signup_PW + "\n" + Signup_PW2 + "\n" + Signup_NICKNAME + "\n" + Signup_NAME +"\n"+ Signup_GENDER;
	MessageBox(test);
	CDialogEx::OnOK();
}


void CSignUpDlg::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_SGender = 0;
	UpdateData(false);

}


void CSignUpDlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_SGender = 1;
	UpdateData(false);
}
