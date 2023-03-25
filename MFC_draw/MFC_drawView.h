// MFC_drawView.h: CMFCdrawView 类的接口
//

#pragma once


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
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
protected:
	CPoint m_point;
};

#ifndef _DEBUG  // MFC_drawView.cpp 中的调试版本
inline CMFCdrawDoc* CMFCdrawView::GetDocument() const
   { return reinterpret_cast<CMFCdrawDoc*>(m_pDocument); }
#endif

