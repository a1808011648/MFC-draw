// MFC_drawView.h: CMFCdrawView 类的接口
//

#pragma once

enum DRAW_TYPE
{
	DT_LINE=0,
	DT_RECT,
	DT_ELLIPSE,
	DT_PEN
};
class CMFCdrawView : public CView
{
protected: // 仅从序列化创建
	CMFCdrawView() noexcept;
	DECLARE_DYNCREATE(CMFCdrawView)

// 特性
public:
	CMFCdrawDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCdrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
protected:
	CPoint m_point;
public:
//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
	unsigned int m_nWidth;
	DRAW_TYPE m_drawType;
public:
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawPen();
protected:
	bool m_bLine;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawPen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawEllipse(CCmdUI* pCmdUI);
protected:
	CMenu m_menu;
public:
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnFileSetup();
protected:
	UINT m_nLineWidth;
	int m_nLineStyle;
	COLORREF m_color;
};

#ifndef _DEBUG  // MFC_drawView.cpp 中的调试版本
inline CMFCdrawDoc* CMFCdrawView::GetDocument() const
   { return reinterpret_cast<CMFCdrawDoc*>(m_pDocument); }
#endif

