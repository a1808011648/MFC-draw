
// MFC_drawView.cpp: CMFCdrawView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_draw.h"
#endif

#include "MFC_drawDoc.h"
#include "MFC_drawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "SetUp.h"


// CMFCdrawView
#define TIMER_TEXT 9527
IMPLEMENT_DYNCREATE(CMFCdrawView, CView)

BEGIN_MESSAGE_MAP(CMFCdrawView, CView)
	ON_WM_CONTEXTMENU()
//	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
//	ON_WM_NCLBUTTONUP()
ON_WM_LBUTTONUP()
//ON_WM_RBUTTONDOWN()
//ON_WM_RBUTTONUP()
//ON_WM_CHAR()
ON_WM_KEYDOWN()
ON_WM_CREATE()
ON_WM_TIMER()
ON_COMMAND(ID_DRAW_LINE, &CMFCdrawView::OnDrawLine)
ON_COMMAND(ID_DRAW_RECT, &CMFCdrawView::OnDrawRect)
ON_COMMAND(ID_DRAW_ELLIPSE, &CMFCdrawView::OnDrawEllipse)
ON_COMMAND(ID_DRAW_PEN, &CMFCdrawView::OnDrawPen)
ON_WM_MOUSEMOVE()
ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CMFCdrawView::OnUpdateDrawLine)
ON_UPDATE_COMMAND_UI(ID_DRAW_PEN, &CMFCdrawView::OnUpdateDrawPen)
ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &CMFCdrawView::OnUpdateDrawRect)
ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, &CMFCdrawView::OnUpdateDrawEllipse)
ON_WM_RBUTTONUP()
ON_COMMAND(ID_FILE_SETUP, &CMFCdrawView::OnFileSetup)
END_MESSAGE_MAP()

// CMFCdrawView 构造/析构

CMFCdrawView::CMFCdrawView() noexcept
{
	// TODO: 在此处添加构造代码
	m_drawType = DT_LINE;
	m_nWidth = 0;
	m_bLine = false;
	m_nLineWidth = 1;
	m_nLineStyle = 0;
	
}

CMFCdrawView::~CMFCdrawView()
{
}

BOOL CMFCdrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	m_menu.LoadMenuW(IDR_MENU1);
	return CView::PreCreateWindow(cs);
}

// CMFCdrawView 绘图

void CMFCdrawView::OnDraw(CDC* pDC)
{
	CMFCdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int len = m_Graph.size();

	//窗口重绘时，将之前存放的绘画记录重新画出来
	for (int i = 0 ; i < len; i++)
	{
		Graph* tempGr = &(m_Graph.at(i));
		CPen pen(tempGr->m_nLineStyle, tempGr->m_penSize, tempGr->m_color);
		CPen* oldPen = pDC->SelectObject(&pen);
		CBrush* brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush* oldBrush = pDC->SelectObject(brush);
		CRect rect(tempGr->m_arrayPoint[0], tempGr->m_arrayPoint[1]);
		int len = tempGr->m_arrayPoint.size();
		int j = 0;
		switch (tempGr->m_drawType)
		{
		case DT_PEN:
			while (len >= 0)
			{
				pDC->MoveTo(tempGr->m_arrayPoint[j]);
				j++;
				if (j == len - 1) {
					break;
				}
				pDC->LineTo(tempGr->m_arrayPoint[j]);
			}
			break;
		case DT_LINE:
			pDC->MoveTo(tempGr->m_arrayPoint[0]);
			pDC->LineTo(tempGr->m_arrayPoint[1]);
			break;
		case DT_RECT:
			pDC->Rectangle(rect);
			break;
		case DT_ELLIPSE:
			pDC->Ellipse(rect);
			break;
		default:
			break;
		}

		//恢复设备
		pDC->SelectObject(oldPen);
		pDC->SelectObject(oldBrush);
	}

}

//void CMFCdrawView::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

void CMFCdrawView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCdrawView 诊断

#ifdef _DEBUG
void CMFCdrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCdrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCdrawDoc* CMFCdrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCdrawDoc)));
	return (CMFCdrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCdrawView 消息处理程序


void CMFCdrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//保存起点到成员变量
	m_point = point; 
	if (m_drawType == DT_PEN) {
		m_bLine = true;
		Graph tempGr;
		tempGr.setGraph(m_drawType, m_color, m_nLineWidth,m_nLineStyle);
		m_Graph.push_back(tempGr);
	}
	
	CView::OnLButtonDown(nFlags, point);
}


//void CMFCdrawView::OnNcLButtonUp(UINT nHitTest, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	
//	CView::OnNcLButtonUp(nHitTest, point);
//}


void CMFCdrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//两点之间画线
	//获取设备上下文
	m_bLine = false;
	CClientDC dc(this);

	//设置画笔和画刷
	CPen pen(m_nLineStyle, m_nLineWidth, m_color);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush* oldBrush = dc.SelectObject(brush);
	CRect rect(m_point, point);\
	switch (m_drawType)
	{
	case DT_LINE:
		dc.MoveTo(m_point);
		dc.LineTo(point);
		break;
	case DT_RECT:
		dc.Rectangle(rect);
		break;
	case DT_ELLIPSE:
		dc.Ellipse(rect);
		break;
	default:
		break;
	}

	//恢复设备
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);

	//保存之前绘画的记录到CArray数组里面
	if (m_nLineStyle != DT_PEN) {
		Graph tempGr;
		tempGr.setGraph(m_drawType, m_color, m_nLineWidth, m_nLineStyle);
		tempGr.AddPoint(m_point, point);
		m_Graph.push_back(tempGr);
	}
	

	


	CView::OnLButtonUp(nFlags, point);
}





//void CMFCdrawView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	//MessageBox(_T("AAAA"));
//	
//
//
//	CView::OnChar(nChar, nRepCnt, nFlags);
//}


void CMFCdrawView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == VK_F1) {

		//获取设备上下文
		CClientDC dc(this);

		//设置设备字体 和颜色
		CFont font;
		font.CreatePointFont(200, _T("华文行楷"), NULL);
		CFont* oldFont = dc.SelectObject(&font);
		COLORREF oldcolore;
		oldcolore = dc.SetTextColor(m_color);

		//画出字体
		CString cstr = _T("你好啊，亲爱的!");
		CSize cSize = dc.GetTextExtent(cstr);
		dc.DrawText(cstr, CRect(m_point.x, m_point.y, m_point.x + cSize.cx, m_point.y + cSize.cy), DT_LEFT);

		//恢复设备
		dc.SelectObject(oldFont);
		dc.SetTextColor(oldcolore);

	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


int CMFCdrawView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//SetTimer(TIMER_TEXT, 100, NULL);

	return 0;
}


void CMFCdrawView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//获取设备
	CClientDC dc(this);
	//设备更换字体和颜色
	CFont font;
	font.CreatePointFont(200, _T("华文行楷"),NULL);
	CFont* oldFont = dc.SelectObject(&font);
	COLORREF oldColor = dc.SetTextColor(m_color);
	
	//准备参数
	CString str(_T("我有一言，不知当讲不当讲!\n我有一错，不知当认不当认！\n我曾言错！如今悔过！"));
	CSize cSize;
	CRect rect;
	switch (nIDEvent)
	{
	case TIMER_TEXT:
		cSize = dc.GetTextExtent(str);
		m_nWidth += 10;
		rect.left = 200;
		rect.top = 100;
		rect.right = rect.left + m_nWidth;
		rect.bottom = rect.top + cSize.cy * 3;
		//画出字体
		dc.DrawText(str, rect, DT_LEFT);
		if (m_nWidth > cSize.cx / 3 * 2) {
			m_nWidth = 0;
			//擦除屏幕 重新显示
			Invalidate();
		}

		//恢复设备
		dc.SelectObject(oldFont);
		dc.SetTextColor(oldColor);
		break;
	default:
		break;
	}

	CView::OnTimer(nIDEvent);
}


void CMFCdrawView::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	m_drawType = DT_LINE;
}


void CMFCdrawView::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	m_drawType = DT_RECT;
}


void CMFCdrawView::OnDrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_drawType = DT_ELLIPSE;
}


void CMFCdrawView::OnDrawPen()
{
	// TODO: 在此添加命令处理程序代码
	m_drawType = DT_PEN;
}


void CMFCdrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_bLine) {
		CClientDC dc(this);

		//画线 设置画笔
		CPen pen(m_nLineStyle, m_nLineWidth, m_color);
		CPen* oldPen = dc.SelectObject(&pen);
		dc.MoveTo(m_point);
		dc.LineTo(point);
		m_point = point;
		auto it = m_Graph.rbegin();
		it->AddPoint(point);
		//恢复设备
		dc.SelectObject(oldPen);
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCdrawView::OnUpdateDrawLine(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_drawType == DT_LINE);
}


void CMFCdrawView::OnUpdateDrawPen(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_drawType == DT_PEN);
}


void CMFCdrawView::OnUpdateDrawRect(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_drawType == DT_RECT);
}


void CMFCdrawView::OnUpdateDrawEllipse(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_drawType == DT_ELLIPSE);
}


void CMFCdrawView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CMenu* mu = m_menu.GetSubMenu(0);

	ClientToScreen(&point);

	mu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y,this);

	CView::OnRButtonUp(nFlags, point);
}


void CMFCdrawView::OnFileSetup()
{
	// TODO: 在此添加命令处理程序代码
	SetUp slid;
	slid.m_nLisder = m_nLineWidth;
	slid.m_nLineStyle = m_nLineStyle;
	slid.m_color = m_color;
	if (IDOK == slid.DoModal()) {
		m_nLineWidth = slid.m_nLisder;
		m_nLineStyle = slid.m_nLineStyle;
		m_color = slid.m_color;
	}

}
