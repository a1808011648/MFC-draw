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
		// 存储操作，写入数据
		ar << m_drawType << m_color << m_penSize << m_nLineStyle;
		int nSize = m_arrayPoint.size(); // 获取vector的大小
		ar << nSize; // 先写入vector的大小信息
		std::for_each(m_arrayPoint.begin(), m_arrayPoint.end(), [&](POINT& pt) {
			ar << pt.x << pt.y; // 遍历vector中的每个元素，写入它们的x和y坐标
		});
	}else{	// loading code
		// 加载操作，读取数据
		ar >> m_drawType >> m_color >> m_penSize >> m_nLineStyle;
		int nSize = 0;
		ar >> nSize; // 先读取vector的大小信息
		for (int i = 0; i < nSize; i++)
		{
			POINT pt;
			ar >> pt.x >> pt.y; // 读取每个元素的x和y坐标，存入pt结构体中
			m_arrayPoint.push_back(pt); // 将pt结构体添加到vector中
		}
	}
}
