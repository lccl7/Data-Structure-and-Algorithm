#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100;

int r[maxn], s[maxn];
int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

void extendbottomupcutrod(int p[], int len, int n)
{
    r[0] = 0;
    for(int j = 1; j <= n; j++)
    {
        int q = -1;
        for(int i = 1; i <= j; i++)
        {
            if(q < p[i] + r[j-i])
            {
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}

int memoization(int p[],int r[], int len, int n)
{
    if(r[n] >= 0)
        return r[n];
    int q;
    if(n == 0)
        q = 0;
    else
        q = -1;
    for(int i = 1; i <= n; i++)
    {
        if(q < p[i] + memoization(p, r, len, n-i))
        {
            q = p[i] + memoization(p, r, len, n-i);
            s[n] = i;
        }
    }
    r[n] = q;
    return q;
}

void print_cut_rod_solution(int p[], int len, int n)
{
    //extendbottomupcutrod(p, len, n);
    memoization(p, r, len, n);
    cout << r[n] << endl;
    while(n > 0)
    {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << endl;
}

int main()
{
//    vector<int> v;
//    v.assign(p, p+11);
    int n;
    memset(r, -1, sizeof(r));
    while(cin >> n)
        print_cut_rod_solution(p, 11,  n);
//        cout << memoization(p, r, 11, n) << endl;
}
