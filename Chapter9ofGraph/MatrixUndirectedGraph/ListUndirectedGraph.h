#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#define MAX 100

class ListUDG
{
private:
    class ENode
    {
    public:
        int ivex;           //该边所指向的顶点的位置
        ENode *nextEdge;    //指向下一条弧的指针
    };
    class VNode
    {
    public:
        char data;          //顶点信息
        ENode *firstEdge;   //指向第一条依附该点的弧
    };

private:
    int mVexNum;
    int mEdgNum;
    VNode mVexs[MAX];

public:
    //创建邻接表对应的图
    ListUDG();
    ListUDG(char vexs[], int vlen, char edges[][2], int elen);
    ~ListUDG();

    void DFS();
    void BFS();
    void print();

private:
    char readChar();
    int getPosition(char ch);
    void DFS(int i, int *visited);
    void linkLast(ENode *list, ENode *node);//将node链接到list的最后
};

