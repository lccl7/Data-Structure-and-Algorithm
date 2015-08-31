#include "MatrixUndirectedGraph.h"

MatrixUDG::MatrixUDG()
{
    char c1, c2;
    int p1, p2;

    //输入顶点数和边数
    cout << "input vertex number: ";
    cin >> mVexNum;
    cout << "input edge number: ";
    cin >> mEdgNum;
    if(mVexNum < 1 || mEdgNum < 1 || (mEdgNum > (mVexNum * (mVexNum -1))))
    {
        cout << "input error: invalid parameters!" << endl;
        return;
    }

    //初始化“顶点”
    for(int i = 0; i < mVexNum; i++)
    {
        cout << "vertex(" << i << "): ";
        mVexs[i] = readChar();
    }
    //初始化“边”
    for(int i = 0; i < mEdgNum; i++)
    {
        cout << "edge(" << i << "): ";
        c1 = readChar();
        c2 = readChar();

        p1 = getPosition(c1);
        p2 = getPosition(c2);
        if(p1 == -1 || p2 == -1)
        {
            cout << "input error: invalid edge!" << endl;
            return;
        }

        mMatrix[p1][p2] = 1;
        mMatrix[p2][p1] = 1;
    }
}

MatrixUDG::MatrixUDG(char vexs[], int vlen, char edges[][2], int elen)
{
    int p1, p2;
    mVexNum = vlen;
    mEdgNum = elen;

    for(int i = 0; i < mVexNum; i++)
        mVexs[i] = vexs[i];

    for(int i = 0; i < mEdgNum; i++)
    {
        p1 = getPosition(edges[i][0]);
        p2 = getPosition(edges[i][1]);
        mMatrix[p1][p2] = 1;
        mMatrix[p2][p1] = 1;
    }
}

MatrixUDG::~MatrixUDG()
{
}

int MatrixUDG::getPosition(char ch)
{
    for(int i = 0; i < mVexNum; i++)
        if(mVexs[i] == ch)
            return i;
    return -1;
}

char MatrixUDG::readChar()
{
    char ch;
    do{
        cin >> ch;
    }while(!((ch >= 'a'&& ch <= 'z') || (ch >= 'A' && ch <= 'Z')));

    return ch;
}

int MatrixUDG::firstVertex(int v)
{
    if(v < 0 || v > (mVexNum - 1))
        return -1;
    for(int i = 0; i < mVexNum; i++)
        if(mMatrix[v][i] == 1)
            return i;
    return -1;
}

int MatrixUDG::nextVertex(int v, int w)
{
    if(v < 0 || v > (mVexNum - 1) || w < 0 || w > (mVexNum - 1))
        return -1;
    for(int i = w + 1; i < mVexNum; i++)
        if(mMatrix[v][i] == 1)
            return i;
    return -1;
}

void MatrixUDG::DFS(int i, int *visited)
{
    visited[i] = 1;
    cout << mVexs[i] << " ";

    //遍历访问所有邻接顶点，若没访问过， 那么继续往下走
    for(int w = firstVertex(i); w >= 0; w = nextVertex(i, w))
    {
        if(!visited[w])
            DFS(w, visited);
    }
}

void MatrixUDG::DFS()
{
    int visited[MAX];
    for(int i = 0; i < mVexNum; i++)
        visited[i] = 0;
    cout << "DFS: ";
    for(int i = 0; i < mVexNum; i++)
    {
        if(!visited[i])
            DFS(i, visited);
    }
    cout << endl;
}

void MatrixUDG::BFS()
{
    int head = 0, rear = 0;
    int queue[MAX], visited[MAX];

    for(int i =0; i < mVexNum; i++)
        visited[i] = 0;
    cout << "BFS: ";
    for(int i =0; i < mVexNum; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            cout << mVexs[i] << " ";
            queue[rear++] = i; //入队列
        }
        while(head != rear)
        {
            int j = queue[head++];
            for(int k = firstVertex(j); k >= 0; k = nextVertex(j, k))
            {
                if(!visited[k])
                {
                    visited[k] = 1;
                    cout << mVexs[k] << " ";
                    queue[rear++] = k;
                }
            }
        }
    }
    cout << endl;
}

void MatrixUDG::print()
{
    cout << "Matrix Graph:" << endl;
    for(int i = 0; i < mVexNum; i++)
    {
        for(int j = 0; j < mVexNum; j++)
            cout << mMatrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'C'}, {'A', 'D'},
        {'A', 'F'}, {'B', 'C'},
        {'C', 'D'}, {'E', 'G'},
        {'F', 'G'}
    };
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    MatrixUDG* pG;

    pG = new MatrixUDG(vexs, vlen, edges, elen);

    pG->print();
    pG->DFS();
    pG->BFS();

    return 0;
}
