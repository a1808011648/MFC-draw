#pragma once
#include <afx.h>
#include <vector>
class Graph:public CObject
{
public:

    //MFC--类的序列化，使用宏
    DECLARE_SERIAL(Graph);
    void setGraph(UINT lineType,COLORREF color,int penSize,int lineStyle);
    Graph();
    void AddPoint(POINT point);
    void AddPoint(POINT start, POINT end);
   


    UINT m_drawType;  //存放画笔类型
    std::vector <POINT> m_arrayPoint; //存放画图的坐标
    COLORREF m_color; //存放画笔颜色
    int m_penSize; //存放画笔大小
    int m_nLineStyle;
    virtual void Serialize(CArchive& ar);
};

