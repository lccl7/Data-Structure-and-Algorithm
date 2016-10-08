#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int i)
{
    for(int j = 2; j*j <= i; j++)
        if(i % j == 0)
            return false;
    return true;
}

void primering1(int n, vector<bool>& isp)
{
    //vector<bool> isp(3*n, false);
    //for(int i = 2; i <= 2 * n; i++)
    //    isp[i] = is_prime(i);
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++)
        v[i] = i+1;
    do {
        bool flag = true;
        for(int i = 0; i < n; i++)
            if(!isp[v[i]+v[(i+1)%n]])
            {
                flag = false; break;
            }
        if(flag)
        {
            for(int i = 0; i < n; i++)
                cout << v[i] << " ";
            cout << endl;
        }
    } while (next_permutation(v.begin()+1, v.end()));
}

void primering2(int n, int cur, vector<bool>& isp, vector<int>& v, vector<bool>& vis)
{
    if(cur == n && isp[v[0]+ v[n-1]])
    {
        for(int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    else {
        for(int i = 2; i <= n; i++)
            if(vis[i] == false && isp[i + v[cur-1]])
            {
                v[cur] = i;
                vis[i] = true;
                primering2(n, cur+1, isp, v, vis);
                vis[i] = false;
            }
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        //generate a prime number table
        vector<bool> isp(3*n, false);
        for(int i = 2; i <= 2 * n; i++)
            isp[i] = is_prime(i);

        vector<bool> vis(n*2, false);
        vector<int> v(n, 0);
        v[0] = 1;
       // primering1(n, isp);
        primering2(n, 1, isp, v, vis);
    }
}
