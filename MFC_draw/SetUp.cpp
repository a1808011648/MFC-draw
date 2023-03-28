// SetUp.cpp: 实现文件
//

#include "pch.h"
#include "MFC_draw.h"
#include "SetUp.h"
#include "afxdialogex.h"


// SetUp 对话框

IMPLEMENT_DYNAMIC(SetUp, CDialogEx)

SetUp::SetUp(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ID_DLG_SETUP, pParent)
	, m_nLisder(0)
	, m_nLineStyle(0)
{
	m_color = RGB(0, 0, 0);
}

SetUp::~SetUp()
{
}

void SetUp::DoDataExchange(CDataExchange* pDX)
{

	DDX_Slider(pDX, IDC_SLIDER1, m_nLisder);
	DDV_MinMaxUInt(pDX, m_nLisder, 1, 30);
	DDX_Radio(pDX, IDC_RADIO1, m_nLineStyle);
}


BEGIN_MESSAGE_MAP(SetUp, CDialogEx)
	ON_BN_CLICKED(IDC_COLOR, &SetUp::OnBnClickedColor)
	ON_BN_CLICKED(IDC_RADIO1, &SetUp::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &SetUp::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &SetUp::OnBnClickedRadio3)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// SetUp 消息处理程序


BOOL SetUp::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CSliderCtrl* slid = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	slid->SetRange(1, 30);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void SetUp::OnBnClickedColor()
{
	// TODO: 在此添加控件通知处理程序代码
	//打开颜色对话框
	CColorDialog colorDlg;
	colorDlg.m_cc.Flags += CC_RGBINIT;
	colorDlg.m_cc.rgbResult = m_color;

	if (IDOK == colorDlg.DoModal()) {
		m_color = colorDlg.m_cc.rgbResult;
		Invalidate();
	}
}


void SetUp::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();
}


void SetUp::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();
}


void SetUp::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();
}


void SetUp::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()

	UpdateData();

	//设备更换画笔和画刷
	CPen pen(m_nLineStyle, m_nLisder, m_color);
	CPen* oldPen = dc.SelectObject(&pen);

	//得到坐标
	CRect rect;
	this->GetDlgItem(IDC_EXAMPLES)->GetWindowRect(rect);
	ScreenToClient(rect);

	//画线
	dc.MoveTo(rect.left + 20, rect.top + rect.Height() / 2);
	dc.LineTo(rect.right - 20, rect.top + rect.Height() / 2);


	//恢复设备
	dc.SelectObject(oldPen);

}


void SetUp::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate();
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
