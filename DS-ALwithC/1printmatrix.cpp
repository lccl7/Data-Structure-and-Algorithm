#include  <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<vector<int>> matrix{{1,2,3,4}, {5,6,7,8},{9,10,11,12}, {13,14,15,16}};
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> vb(m, vector<bool>(n, true));
    int i = 0;
    int row = 0, col = 0;
    while(i < m * n)
    {
        while(i < m * n && col < n && vb[row][col])
        {
            cout << matrix[row][col] << " ";
            vb[row][col] = false;
            col++;
            i++;
        }
        col--;
        row++;
        while(i < m * n && row < m && vb[row][col])
        {
            cout << matrix[row][col] << " ";
            vb[row][col] = false;
            row++;
            i++;
        }
        row--;
        col--;
        while(i < m * n && col >= 0 && vb[row][col])
        {
            cout << matrix[row][col] << " ";
            vb[row][col] = false;
            col--;
            i++;
        }
        col++;
        row--;
        while(i < m * n && row >= 0 && vb[row][col])
        {
            cout << matrix[row][col] << " ";
            vb[row][col] = false;
            row--;
            i++;
        }
        row++;
        col++;
    }
    cout << endl;

    return 0;
}
