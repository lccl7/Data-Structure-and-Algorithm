#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

class MatrixUDG
{
private:
    char mVexs[MAX]; //顶点集合
    int mVexNum;    //顶点数
    int mEdgNum;    //边数
    int mMatrix[MAX][MAX]; //邻接矩阵

public:
    //创建图
    MatrixUDG();
    //创建图（用已提供的矩阵）
    MatrixUDG(char vexs[], int vlen, char edges[][2], int elen);
    ~MatrixUDG();
    void DFS();
    void BFS();
    void print();

private:
    //读取字符
    char readChar();
    //返回ch在mMatrix矩阵中的位置
    int getPosition(char ch);
    //返回顶点v的第一个邻接顶点的索引
    int firstVertex(int v);
    //返回顶点v相对w的下一个邻接顶点的索引
    int nextVertex(int v, int w);
    //递归DFS
    void DFS(int i, int *visited);
};
