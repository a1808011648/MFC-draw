#include "pch.h"
#include "Graph.h"
#include <algorithm>
IMPLEMENT_SERIAL(Graph, CObject, 1);

void Graph::setGraph(UINT lineType, COLORREF color, int penSize, int lineStyle)
{
	m_drawType = lineType;
	m_color = color;
	m_penSize = penSize;
	m_nLineStyle = lineStyle;
}

Graph::Graph()
{
}



void Graph::AddPoint(POINT point)
{
	m_arrayPoint.push_back(point);
}

void Graph::AddPoint(POINT start, POINT end)
{
	m_arrayPoint.push_back(start);
	m_arrayPoint.push_back(end);
}


void Graph::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		// �洢������д������
		ar << m_drawType << m_color << m_penSize << m_nLineStyle;
		int nSize = m_arrayPoint.size(); // ��ȡvector�Ĵ�С
		ar << nSize; // ��д��vector�Ĵ�С��Ϣ
		std::for_each(m_arrayPoint.begin(), m_arrayPoint.end(), [&](POINT& pt) {
			ar << pt.x << pt.y; // ����vector�е�ÿ��Ԫ�أ�д�����ǵ�x��y����
		});
	}else{	// loading code
		// ���ز�������ȡ����
		ar >> m_drawType >> m_color >> m_penSize >> m_nLineStyle;
		int nSize = 0;
		ar >> nSize; // �ȶ�ȡvector�Ĵ�С��Ϣ
		for (int i = 0; i < nSize; i++)
		{
			POINT pt;
			ar >> pt.x >> pt.y; // ��ȡÿ��Ԫ�ص�x��y���꣬����pt�ṹ����
			m_arrayPoint.push_back(pt); // ��pt�ṹ����ӵ�vector��
		}
	}
}
