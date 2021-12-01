
// GameProjectView.cpp: CGameProjectView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "GameProject.h"
#endif

#include "GameProjectDoc.h"
#include "GameProjectView.h"
#include "CSignupDlg.h"

#include "MFC_game.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <string>
#include <atlimage.h>

// CGameProjectView

IMPLEMENT_DYNCREATE(CGameProjectView, CFormView)

BEGIN_MESSAGE_MAP(CGameProjectView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_SignUp, &CGameProjectView::OnBnClickedSignup)
	ON_BN_CLICKED(IDC_btn_Login, &CGameProjectView::OnBnClickedbtnLogin)
	ON_BN_CLICKED(IDC_FindInfo, &CGameProjectView::OnBnClickedFindinfo)
END_MESSAGE_MAP()

// CGameProjectView 생성/소멸

CGameProjectView::CGameProjectView() noexcept
	: CFormView(IDD_GAMEPROJECT_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	BOOL bopen = m_db.OpenEx(_T("DSN=mydb; SERVER=127.0.0.1; PORT=3306; UID=anni20; PWD=0804; DATABASE=gameproject ;"), CDatabase::noOdbcDialog);
	if (bopen) m_prs = new CRecordset(&m_db);

	m_LoginCheck = 0;

	level = 0;
	start = 0;
	x = 0;
	y = 0;
	step = 10;
	count = 0;
	gover = 0;
	m_winright = 0;
	m_winbottom = 0;

}

CGameProjectView::~CGameProjectView()
{
}

void CGameProjectView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CGameProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CGameProjectView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	//GetDlgItem(IDC_FindInfo)->EnableWindow(FALSE); // 아이디/비밀번호 찾기 비활성화

	// 화면 전환
	CRect rc;
	GetClientRect(&rc);
	//rc.left += 100;

	CCreateContext cc;

	/* formview 전환 부분
	CView* pView = (CView*)RUNTIME_CLASS(MFC_game)->CreateObject();
	ZeroMemory(&cc, sizeof(cc));
	pView->Create(nullptr, nullptr, WS_CHILD, rc, this, IDD_Play, &cc);
	pView->OnInitialUpdate();
	m_PlayView = pView;*/

}


// CGameProjectView 인쇄

BOOL CGameProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGameProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGameProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CGameProjectView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CGameProjectView 진단

#ifdef _DEBUG
void CGameProjectView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGameProjectView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGameProjectDoc* CGameProjectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGameProjectDoc)));
	return (CGameProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CGameProjectView 메시지 처리기


void CGameProjectView::OnBnClickedSignup()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSignUpDlg SignUp_Screen; 
	int iRes = SignUp_Screen.DoModal(); // 회원 가입창 모달
	//SignUp_Screen.EndDialog(IDOK);
}


void CGameProjectView::OnBnClickedbtnLogin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	//아이디, 비밀번호 입력
	CString m_Login_ID = _T("");
	CString m_Login_PW = _T("");
	
	
	GetDlgItemText(IDC_ID, m_Login_ID);
	GetDlgItemText(IDC_Password, m_Login_PW);

	//입력 테스트
	/*
	CString test = m_Login_ID +" " + m_Login_PW;
	MessageBox(test);
	*/

	if (m_Login_ID.Compare(_T("")) != 0 || m_Login_PW.Compare(_T("")) != 0) {
		int success = ComparePW(m_Login_ID, m_Login_PW);
		if (success == 1) {
			MessageBox(_T("로그인을 성공하였습니다."));
			// m_PlayView->ShowWindow(SW_SHOW); 폼뷰 전환 부분
			Clear_LoginScreen();
			
			
		}
		else MessageBox(_T("잘못된 아이디/비밀번호 입니다.\n다시 로그인을 시도해주세요."));
	}
	else MessageBox(_T("아이디/비밀번호를 입력해주세요."));
	
}

int CGameProjectView::ComparePW(CString  Enter_ID, CString Enter_PW) {

	CString query_str; //쿼리문
	CString m_ComparePW = _T(""); //DB에 있는 비밀번호와 비교

	query_str.Format(L"select PW from member where ID = \'%s\';", Enter_ID);


	BOOL bopen = m_prs->Open(CRecordset::snapshot, query_str);

	{
		int row = 1;
		BOOL beof = m_prs->IsEOF();
		DWORD dwsize = m_prs->GetRowsetSize();
		if (!beof) {
			for (m_prs->MoveFirst(); !m_prs->IsEOF(); m_prs->MoveNext()) {
				
				for (int col = 0; col < 1; col++) {
					m_prs->SetAbsolutePosition(row);
					m_prs->GetFieldValue(col, m_ComparePW);
				} 
			} 
		}  
		//AfxMessageBox(m_ComparePW);  //알맞은 비밀번호
		m_prs->Close();
	}

	if (Enter_PW == m_ComparePW) return 1;
	else return 0;
}



void CGameProjectView::OnBnClickedFindinfo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFindDlg Find_Screen;
	int iRes = Find_Screen.DoModal();
}

void CGameProjectView::Clear_LoginScreen() {

	GetDlgItem(IDC_SignUp)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_btn_Login)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FindInfo)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ID)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Password)->ShowWindow(SW_HIDE);
}




void CGameProjectView::OnDraw(CDC* pDC)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (m_LoginCheck == 1) {
	

		CClientDC dc(this);
		CRect rect;
		GetClientRect(&rect);

		// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
		if (gover == 0) {
			CDC memdc;
			CBitmap* p0ldBitmap, bitmap;

			memdc.CreateCompatibleDC(&dc);
			bitmap.CreateCompatibleBitmap(&dc, rect.right, rect.bottom);
			p0ldBitmap = memdc.SelectObject(&bitmap);

			CBrush bs(RGB(255, 255, 255));
			memdc.SelectObject(&bs);
			memdc.Rectangle(0, 0, rect.right, rect.bottom);

			int delay;
			delay = rand() % 10 + 1;

			CString str, str2;

			if (level == 0)
				str2.Format(L"EASY");
			else if (level == 1)
				str2.Format(L"NORMAL");
			else if (level == 2)
				str2.Format(L"HARD");
			else if (level == 3)
				str2.Format(L"HELL");

			str.Format(L"누르면 게임시작\n난이도는 %s입니다.", str2);

			if (start == 0) {
				MessageBox(str);
				start = !start;
			}

			SetTimer(0, 10, NULL);
			//easy , nomal , hard , hell

			switch (level) {


			case 0:
				if (delay == 5)
					for (int i = 0; i < 1; i++) {
						k.push_back(0);
						int r = rand() % 11 + 10;
						er.push_back(r);
						k[i].x = rand() % (rect.right - 99) + 50;
						k[i].y = -1 * (100 * (delay));
						e.push_back(k[i]);
						step_y.push_back(rand() % 2 + 4);
						if (e[i].y - er[i] >= rect.bottom)
							count++;
						else if (e[i].y - er[i] >= m_winbottom)
							return;
					}
				break;

			case 1:
				if (delay % 5 == 0)
					for (int i = 0; i < 1; i++) {
						k.push_back(0);
						int r = rand() % 11 + 10;
						er.push_back(r);
						k[i].x = rand() % (rect.right - 99) + 50;
						k[i].y = -1 * (100 * (delay));
						e.push_back(k[i]);
						step_y.push_back(rand() % 2 + 4);
					}
				break;

			case 2:
				if (delay % 3 == 0)
					for (int i = 0; i < 1; i++) {
						k.push_back(0);
						int r = rand() % 11 + 10;
						er.push_back(r);
						k[i].x = rand() % (rect.right - 99) + 50;
						k[i].y = -1 * (100 * (delay));
						e.push_back(k[i]);
						step_y.push_back(rand() % 2 + 4);
					}
				break;

			case 3:
				if (delay % 2 == 0)
					for (int i = 0; i < 1; i++) {
						k.push_back(0);
						int r = rand() % 11 + 10;
						er.push_back(r);
						k[i].x = rand() % (rect.right - 99) + 50;
						k[i].y = -1 * (100 * (delay));
						e.push_back(k[i]);
						step_y.push_back(rand() % 2 + 4);
					}
				break;
			}
			for (int i = 0; i < e.size(); i++) {
				CBrush bs(RGB(255, 255, 220));
				memdc.SelectObject(&bs);
				memdc.Ellipse(e[i].x - er[i], e[i].y - er[i], e[i].x + er[i], e[i].y + er[i]);
			}
			dc.BitBlt(0, 0, rect.right, rect.bottom, &memdc, 0, 0, SRCCOPY);

			str.Format(_T("점수 = %d"), count); //str에 저장
			dc.SetBkMode(TRANSPARENT);
			dc.TextOutW(10, 10, str);



			//사람
			CDC memDC;
			memDC.CreateCompatibleDC(pDC);

			CBitmap bmp;
			bmp.LoadBitmap(IDB_BITMAP1);

			CBitmap* pOldBmp = NULL;
			pOldBmp = memDC.SelectObject(&bmp);

			BITMAP bmpInfo;
			bmp.GetBitmap(&bmpInfo);

			pDC->TransparentBlt(x + m_winright, y + m_winbottom, bmpInfo.bmWidth, bmpInfo.bmHeight, &memDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, RGB(255, 255, 255));

			memDC.SelectObject(pOldBmp);
			memDC.DeleteDC();
			bmp.DeleteObject();

			CBrush bs1, * pbs1;
			CPen pen, * oldpen;
			bs1.CreateStockObject(NULL_BRUSH); //투명 사각형
			pen.CreatePen(PS_NULL, 0, RGB(255, 255, 255)); //선
			pbs1 = dc.SelectObject(&bs1);
			oldpen = dc.SelectObject(&pen);
			dc.Rectangle(x + m_winright + 10, y + m_winbottom, x + m_winright + 35, y + m_winbottom + 50);
			dc.SelectObject(pbs1);
			dc.SelectObject(oldpen);
			pen.DeleteObject();

			if (x + m_winright > m_winright && x > m_winright)
				x = x * -1;
			else if (x + m_winright < m_winright && x < -m_winright)
				x = x * -1;

			int dx, dy;
			double compile;
			for (int i = 0; i < e.size(); i++)
			{
				dx = e[i].x - (x + m_winright + 23);
				dy = e[i].y - (y + m_winbottom + 10);
				compile = sqrt(dx * dx + dy * dy);
				if (compile < er[i]) {
					gover = 1;
					Invalidate();
				}
			}

		}

		else {
			KillTimer(0);
			e.clear();
			er.clear();
			step_y.clear();
			k.clear();
			start = 0;
			CDC mdc;
			CBitmap s_bit, * oldbit;
			mdc.CreateCompatibleDC(pDC);
			s_bit.LoadBitmap(IDB_BITMAP2);
			oldbit = mdc.SelectObject(&s_bit);
			int w, h;
			w = rect.right;
			h = rect.bottom;
			pDC->StretchBlt(w / 4, 100, 10 * w, 10 * h, &mdc, 0, 0, w, h, SRCCOPY);

			mdc.SelectObject(oldbit);
			s_bit.DeleteObject();
			mdc.DeleteDC();

			CString str;
			CFont font, * pOldFont;
			font.CreatePointFont(250, _T("궁서체"));
			pOldFont = (CFont*)dc.SelectObject(&font);
			str.Format(L"최종 점수 = %d ", count);
			dc.SetBkMode(TRANSPARENT);
			dc.TextOut(w - 700, h - 500, str);
			gover = 0;
			count = 0;
			Sleep(2500);
			Invalidate();


		}
	
	
	}
	//else { MessageBox(L"로그인이 필요합니다"); }
}
