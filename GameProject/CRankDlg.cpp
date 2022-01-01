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
	, m_SelectRecord(0)
{
	BOOL bopen = m_db.OpenEx(_T("DSN=mydb;SERVER=127.0.0.1;PORT=3306;UID=root;PWD=0804; DATABASE=gameproject;"), CDatabase::noOdbcDialog);
	if (bopen) m_prs = new CRecordset(&m_db);
}

CRankDlg::~CRankDlg()
{
}

void CRankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_SelectRecord);
	DDX_Control(pDX, IDC_stage, m_selectLevel);
	DDX_Control(pDX, IDC_Record1, m_list1);
	DDX_Control(pDX, IDC_Record2, m_list2);

	m_selectLevel.ResetContent();
	m_selectLevel.InsertString(0, _T("Easy"));
	m_selectLevel.InsertString(1, _T("Normal"));
	m_selectLevel.InsertString(2, _T("Hard"));
	m_selectLevel.InsertString(3, _T("Hell"));
	m_selectLevel.SetCurSel(0);

	m_list1.InsertColumn(0, _T("순위"), LVCFMT_CENTER, 80);
	m_list1.InsertColumn(1, _T("닉네임"), LVCFMT_CENTER, 80);
	m_list1.InsertColumn(2, _T("점수"), LVCFMT_CENTER, 80);
	m_list1.InsertColumn(3, _T("기록 달성일"), LVCFMT_CENTER, 400);

	m_list2.InsertColumn(0, _T("나의 최고 순위"), LVCFMT_CENTER, 120);
	m_list2.InsertColumn(1, _T("닉네임"), LVCFMT_CENTER, 80);
	m_list2.InsertColumn(2, _T("점수"), LVCFMT_CENTER, 80);
	m_list2.InsertColumn(3, _T("기록 달성일"), LVCFMT_CENTER, 400);

	
}


BEGIN_MESSAGE_MAP(CRankDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CRankDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO3, &CRankDlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CRankDlg 메시지 처리기

void CRankDlg::OnBnClickedRadio3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_SelectRecord = 1;
}

void CRankDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	m_list1.DeleteAllItems();

	int idx = m_selectLevel.GetCurSel();
	CString str;
	m_selectLevel.GetLBText(idx, str);

	int level;
	if (str == "Easy") { level = 0; }
	else if (str == "Normal") { level = 1; }
	else if (str == "Hard") { level = 2; }
	else if (str == "Hell") { level = 3; }
	selectQuery(level);

	int count = m_list1.GetItemCount();
	CString id, score, date, rank;
	rank = m_list1.GetItemText(0, 0);
	id = m_list1.GetItemText(0, 1);
	score = m_list1.GetItemText(0, 2);
	date = m_list1.GetItemText(0, 3);

	int row = 0;
	m_list2.InsertItem(row, rank);
	m_list2.SetItemText(row, 1, id);
	m_list2.SetItemText(row, 2, score);
	m_list2.SetItemText(row, 3, date);
}

void CRankDlg::selectQuery(int level) {
	
	CString str_query;
	UpdateData(true);
	switch (m_SelectRecord) {
	case 0:
		str_query.Format(L"select * from(select *, rank() over(order by score desc) As ranking from play_record where level = \'%d\')play_record where nickname =\'%s\' ;",level,player.m_pNICKNAME);
		selectRecord(str_query);
		break;
	case 1:
		str_query.Format(L"select * from(select * , rank() over(order by score desc) As ranking from play_record where level = \'%d\')play_record group by nickname; ", level);
		selectRecord(str_query);
		break;
	}
}


void CRankDlg::selectRecord(CString query) {
	
	BOOL bopen = m_prs->Open(CRecordset::snapshot, query);
	{
		int row = 1;
		BOOL beof = m_prs->IsEOF();
		DWORD dwsize = m_prs->GetRowsetSize();
		if (!beof) {
			for (m_prs->MoveFirst(); !m_prs->IsEOF(); m_prs->MoveNext()) {
				int list_row=row-1;
				CString info;
				m_prs->SetAbsolutePosition(row); //mysql 테이블
				m_prs->GetFieldValue(short(4), info);
				m_list1.InsertItem(list_row, info);

				for (int i = 0; i < 3; i++) {
					m_prs->GetFieldValue(i, info);
					m_list1.SetItemText(list_row, i + 1, info);
				} // for i
				
				row++;
			} // for m_prs
		} // if 
		m_prs->Close();
	}
}

