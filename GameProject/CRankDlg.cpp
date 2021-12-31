// CRankDlg.cpp: 구현 파일
//

#include "pch.h"
#include "GameProject.h"
#include "afxdialogex.h"
#include "CRankDlg.h"


// CRankDlg 대화 상자

IMPLEMENT_DYNAMIC(CRankDlg, CDialogEx)

CRankDlg::CRankDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RANK, pParent)
{

}

CRankDlg::~CRankDlg()
{
}

void CRankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRankDlg, CDialogEx)
END_MESSAGE_MAP()


// CRankDlg 메시지 처리기
