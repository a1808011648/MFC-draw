
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


// CMFCdrawView

IMPLEMENT_DYNCREATE(CMFCdrawView, CView)

BEGIN_MESSAGE_MAP(CMFCdrawView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
//	ON_WM_NCLBUTTONUP()
ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCdrawView 构造/析构

CMFCdrawView::CMFCdrawView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCdrawView::~CMFCdrawView()
{
}

BOOL CMFCdrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCdrawView 绘图

void CMFCdrawView::OnDraw(CDC* /*pDC*/)
{
	CMFCdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCdrawView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCdrawView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
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
	CDC* pDC = GetDC();

	//函数说明：画笔移动到起始点
	pDC->MoveTo(m_point);
	//从起点到终点画线
	pDC->LineTo(point);
	//释放设备上下文
	ReleaseDC(pDC);
	CView::OnLButtonUp(nFlags, point);
}
