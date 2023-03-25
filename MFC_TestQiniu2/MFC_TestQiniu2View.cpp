
// MFC_TestQiniu2View.cpp: CMFCTestQiniu2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_TestQiniu2.h"
#endif

#include "MFC_TestQiniu2Doc.h"
#include "MFC_TestQiniu2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTestQiniu2View

IMPLEMENT_DYNCREATE(CMFCTestQiniu2View, CView)

BEGIN_MESSAGE_MAP(CMFCTestQiniu2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCTestQiniu2View 构造/析构

CMFCTestQiniu2View::CMFCTestQiniu2View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCTestQiniu2View::~CMFCTestQiniu2View()
{
}

BOOL CMFCTestQiniu2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCTestQiniu2View 绘图

void CMFCTestQiniu2View::OnDraw(CDC* /*pDC*/)
{
	CMFCTestQiniu2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCTestQiniu2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCTestQiniu2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCTestQiniu2View 诊断

#ifdef _DEBUG
void CMFCTestQiniu2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTestQiniu2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTestQiniu2Doc* CMFCTestQiniu2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTestQiniu2Doc)));
	return (CMFCTestQiniu2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTestQiniu2View 消息处理程序
