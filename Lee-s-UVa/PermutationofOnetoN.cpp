#include <iostream>
#include <vector>
using namespace std;

void print_permutation(int n, vector<int> &vi, int cur)
{
    if(cur == n)
    {
        for(int i = 0; i < n; i++)
            cout << vi[i] << " ";
        cout << endl;
    }
    else for(int i = 1; i <= n; i++)
    {
        bool ok = true;
        for(int j = 0; j < cur; j++)
            if(vi[j] == i) ok = false;
        if(ok)
        {
            vi[cur] = i;
            print_permutation(n, vi, cur+1);
        }
    }
}

void print_permutation(int n, vector<int> &vi, int cur, vector<int> P)
{
    if(cur == n)
    {
        for(int i = 0; i < n; i++)
            cout << vi[i] << " ";
        cout << endl;
    }
    else
    for(int i = 0; i <= n; i++)
    if(!i || P[i] != P[i-1])
    {
        int c1 = 0, c2 = 0;
        for(int j = 0; j < cur; j++) if(vi[j] == P[i]) c1++;
        for(int j = 0; j < n; j++) if(P[j] == P[i]) c2++;
        if(c1 < c2)
        {
            vi[cur] = P[i];
            print_permutation(n, vi, cur+1, P);
        }
    }
}

void next_per(int n, int *p)
{
    sort(p, p+n);
    do {
        for(int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << endl;
    } while (next_permutation(p, p+n));

    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vi(100, 0);
    int p[] = {1, 2, 2, 3};
    print_permutation(n, vi, 0);
    print_permutation(4, vi, 0, p);
    next_per(n, p);
}
