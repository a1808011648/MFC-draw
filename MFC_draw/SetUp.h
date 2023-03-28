#pragma once


// SetUp 对话框

class SetUp : public CDialogEx
{
	DECLARE_DYNAMIC(SetUp)

public:
	SetUp(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetUp();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_DLG_SETUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
//	UINT m_nSlider;
	int m_nLisder;
	int m_nLineStyle;
	afx_msg void OnBnClickedColor();
	COLORREF m_color;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
