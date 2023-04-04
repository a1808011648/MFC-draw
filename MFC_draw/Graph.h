#pragma once
#include <afx.h>
#include <vector>
class Graph
{
public:
    void setGraph(UINT lineType,COLORREF color,int penSize,int lineStyle);
    Graph() = default;
    void AddPoint(POINT point);
    void AddPoint(POINT start, POINT end);
   


    UINT m_drawType;  //��Ż�������
    std::vector <POINT> m_arrayPoint; //��Ż�ͼ������
    COLORREF m_color; //��Ż�����ɫ
    int m_penSize; //��Ż��ʴ�С
    int m_nLineStyle;
};

