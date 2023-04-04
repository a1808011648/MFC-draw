#include "pch.h"
#include "Graph.h"

void Graph::setGraph(UINT lineType, COLORREF color, int penSize, int lineStyle)
{
	m_drawType = lineType;
	m_color = color;
	m_penSize = penSize;
	m_nLineStyle = lineStyle;
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
