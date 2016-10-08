#include <iostream>
#include <vector>
#include <string>
using namespace std;

void search(int cur, vector<int>& v, vector<string>& vs, int &tot)
{
    if(cur == v.size())
    {
        cout << "the result: " << endl;
        for(auto s: vs)
        {
            cout << s << endl;
        }
        cout << endl;
        tot++;
    }
    else
    for(int i = 0; i < v.size(); i++)
    {
        int ok = 1;
        v[cur] = i;
        for(int j = 0; j < cur; j++)
        {
            if(v[j] == v[cur] || cur - v[cur] == j - v[j] || cur + v[cur] == j + v[j])
            {
                ok = 0; break;
            }
        }
        if(ok)
        {
            vs[cur][i] = 'Q';
            search(cur + 1, v, vs, tot);
            vs[cur][i] = '*';
        }
    }
}

void search2(int cur, vector<vector<bool>> &vis, vector<string> &vs, int &tot)
{
    if(cur == vs.size())
    {
        cout << "the result: " << endl;
        for(auto s: vs)
        {
            cout << s << endl;
        }
        cout << endl;
        tot++;
    }
    else {
        for(int i = 0; i < vs.size(); i++)
        {
            if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+vs.size()])
            {
                vs[cur][i] = 'Q';
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+vs.size()] = true;
                search2(cur + 1, vis, vs, tot);
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+vs.size()] = false;
                vs[cur][i] = '*';
            }
        }
    }
}

int main()
{
    int n, m = 0;
    cin >> n;
    vector<int> v(n, 0);
    vector<vector<bool>> vis(3, vector<bool>(n, false));
    vector<string> vs(n, string(n, '*'));
    //search(0, v, vs, m);
    search2(0, vis, vs, m);
    cout << "there are " << m << " ways" << endl;
}
