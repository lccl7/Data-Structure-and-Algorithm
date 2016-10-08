#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

const int maxn = 1000000 + 5;
int A[maxn];

int main(int argc, char** argv)
{
    fstream infile(argv[1]);
    int T, n;
    infile >> T;
    while(T--)
    {
        infile >> n;
        for(int i = 0; i < n; i++)
            infile >> A[i];

        set<int> s;
        int L = 0, R = 0, ans = 0;
        while(R < n)
        {
            while(R < n && !s.count(A[R]))
                s.insert(A[R++]);
            ans = max(ans, R - L);
            s.erase(A[L++]);
        }
        cout << ans << endl;
    }
    return 0;
}
