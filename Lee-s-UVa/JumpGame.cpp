#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int n, board[100][100];

bool jump(int y, int x)
{
    if(y >= n || x >= n) return false;
    if(y == n-1 && x == n-1) return true;
    int jumpSize = board[y][x];
    return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

int main(int argc, char** argv)
{
    ifstream infile(argv[1]);
    while(infile >> n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                infile >> board[i][j];
        if(jump(0, 0))
            cout << "true" << endl;
        else {
            cout << "false"<< endl;
        }
    }
}
