#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int solve1(vector<vector<int> >& v)
{
    int m = v.size(), n = v[m-1].size();
    cout << m << " " << n << endl;
    vector<vector<int> > res(m, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        res[n-1][i] = v[n-1][i];
    for(int i = n-2; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            res[i][j] = v[i][j] + max(res[i+1][j], res[i+1][j+1]);
    return res[0][0];
}

int solve2(vector<vector<int> >& v, vector<vector<int> >& res, int i, int j)
{
    if(res[i][j] >= 0) //return res[i][j];
        cout << i << "," << j << ":" << res[i][j] << endl;
    return res[i][j] = v[i][j] + (i == v.size()-1 ? 0 : max(solve2(v, res, i+1, j), solve2(v, res, i+1, j+1)));
}

int main(int argc, char** argv)
{
    ifstream infile(argv[1]);
    int T;
    infile >> T;
    vector<vector<int> > vv(T, vector<int>(T, 0));
    vector<vector<int> > res(T, vector<int>(T, -1));
    for(int i = 0; i < T; i++)
        for(int j = 0; j < i+1; j++)
            infile >> vv[i][j];
    cout << solve2(vv, res, 0, 0) << endl;
}
