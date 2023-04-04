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
   


    UINT m_drawType;  //存放画笔类型
    std::vector <POINT> m_arrayPoint; //存放画图的坐标
    COLORREF m_color; //存放画笔颜色
    int m_penSize; //存放画笔大小
    int m_nLineStyle;
};

