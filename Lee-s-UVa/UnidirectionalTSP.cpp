#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//d[i][j] is the least sum that starts from (i, j)
//next[i][j] is the path that from the first column to the last
void TSP(vector<vector<int> >& vv)
{
    int m = vv.size(), n = vv[0].size();
    int ans = INT_MAX, first = 0;
    vector<vector<int> > d(m, vector<int>(n, 0));
    vector<vector<int> > next(m, vector<int>(n, 0));
    for(int j = n-1; j >= 0; j--)
    {
        cout << j << ":" << endl;
        for(int i = 0; i < m; i++)
        {
            if(j == n-1) d[i][j] = vv[i][j];
            else
            {
                int rows[3] = {i, i-1, i+1};
                if(i == 0) rows[1] = m-1;
                if(i == m-1) rows[2] = 0;
                sort(rows, rows + 3);
                d[i][j] = INT_MAX;
                for(int k = 0; k < 3; k++)
                {
                    int v = d[rows[k]][j+1] + vv[i][j];
                    if(v < d[i][j])
                    {
                        d[i][j] = v;
                        next[i][j] = rows[k];
                    }
                }
            }
            if(j == 0 && d[i][j] < ans)
            {
                ans = d[i][j];
                first = i;
            }
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << first + 1 << " ";
    for(int i = next[first][0], j = 1; j < n; i = next[i][j], j++)
        cout << i+1 << " ";
    cout << endl << ans << endl;
}

int main(int argc, char** argv)
{
    ifstream infile(argv[1]);
    int m, n;
    while(infile >> m >> n)
    {
        vector<vector<int> > v(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                infile >> v[i][j];
        TSP(v);
    }
    return 0;
}
