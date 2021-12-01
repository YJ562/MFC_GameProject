// MFC_game.cpp: 구현 파일
//

#include "pch.h"
#include "GameProject.h"
#include "MFC_game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <string>
#include <atlimage.h>


// MFC_game

IMPLEMENT_DYNCREATE(MFC_game, CFormView)

MFC_game::MFC_game()
	: CFormView(IDD_Play)
{

}

MFC_game::~MFC_game()
{
}

void MFC_game::DoDataExchange(CDataExchange* pDX)

{
	level = 0;
	start = 0;
	x = 0;
	y = 0;
	step = 10;
	count = 0;
	gover = 0;
	m_winright = 0;
	m_winbottom = 0;

	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MFC_game, CFormView)
	ON_COMMAND(ID_32771, &MFC_game::Onmyeasy)
	ON_COMMAND(ID_32772, &MFC_game::Onmynomal)
	ON_COMMAND(ID_32773, &MFC_game::Onmyhard)
	ON_COMMAND(ID_32774, &MFC_game::OnmyHell)
	ON_WM_KEYDOWN()
//	ON_WM_ENTERSIZEMOVE()
ON_WM_SIZE()
ON_WM_ERASEBKGND()
//ON_WM_PAINT()
END_MESSAGE_MAP()


// MFC_game 진단

#ifdef _DEBUG
void MFC_game::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void MFC_game::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// MFC_game 메시지 처리기


void MFC_game::OnDraw(CDC* pDC)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

				/*
				CGameProjectDoc* pDoc = GetDocument();
				ASSERT_VALID(pDoc);
				if (!pDoc)
					return;*/

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


void MFC_game::Onmyeasy()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	KillTimer(0);
	level = 0;
	e.clear();
	er.clear();
	step_y.clear();
	k.clear();
	start = 0;
	Invalidate();
}


void MFC_game::Onmynomal()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	KillTimer(0);
	level = 1;
	e.clear();
	er.clear();
	step_y.clear();
	k.clear();
	start = 0;
	Invalidate();
}


void MFC_game::Onmyhard()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	KillTimer(0);
	level = 2;
	e.clear();
	er.clear();
	step_y.clear();
	k.clear();
	start = 0;
	Invalidate();
}




void MFC_game::OnmyHell()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	KillTimer(0);
	level = 3;
	e.clear();
	er.clear();
	step_y.clear();
	k.clear();
	start = 0;
	Invalidate();
}



void MFC_game::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nChar == VK_RIGHT)
		x += step;
	if (nChar == VK_LEFT)
		x -= step;

	Invalidate();
	

	CFormView::OnKeyDown(nChar, nRepCnt, nFlags);
}


//void MFC_game::OnEnterSizeMove()
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	CFormView::OnEnterSizeMove();
//}


void MFC_game::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_winright = cx / 2;
	m_winbottom = cy - 50;
}


BOOL MFC_game::OnPreparePrinting(CPrintInfo* pInfo)
{

	// TODO:  [인쇄] 대화 상자를 호출하는 DoPreparePrinting을 호출합니다.

	return CFormView::OnPreparePrinting(pInfo);
}


BOOL MFC_game::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CFormView::PreCreateWindow(cs);
}


void MFC_game::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CFormView::OnBeginPrinting(pDC, pInfo);
}


void MFC_game::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CFormView::OnEndPrinting(pDC, pInfo);
}


BOOL MFC_game::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return false;

	return CFormView::OnEraseBkgnd(pDC);
}


//void MFC_game::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
//					   // 그리기 메시지에 대해서는 CFormView::OnPaint()을(를) 호출하지 마십시오.
//}
