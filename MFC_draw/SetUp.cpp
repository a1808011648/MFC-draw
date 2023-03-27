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
	CColorDialog colorDlg;
	colorDlg.m_cc.Flags += CC_RGBINIT;
	colorDlg.m_cc.rgbResult = m_color;

	if (IDOK == colorDlg.DoModal()) {
		m_color = colorDlg.m_cc.rgbResult;
	}
}
