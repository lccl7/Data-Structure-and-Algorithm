//For positive integer x, y, 1/x + 1/y = 1/k
//so, y is not less than k, because x is equal or bigger than y
//so, y is not bigger than 2k, we can give all possible numbers
//and calculate x based on this.
#include <iostream>
#include <vector>
using namespace std;

struct triples
{
    int a, b, c;
    triples(int a1, int b1, int c1):a(a1),b(b1),c(c1){}
};

int main()
{
    int count = 0;
    vector<triples> vt;
    int k;
    while(cin >> k)
    {
        vt.clear();
        for(int y = k; y <= 2*k; y++)
        {
            double x1 = 1.0/(1.0/k - 1.0/y);
            int x = (int)x1;
            if(x*y == k*y + k*x)
                vt.push_back(triples(k, x, y));
        }
        cout << vt.size() << endl;
        for(int i = 0; i < vt.size(); i++)
            cout << 1 << "/" << vt[i].a
                << " = "
                << 1 << "/" << vt[i].b
                << " + "
                << 1 << "/" << vt[i].c << endl;
    }
}
