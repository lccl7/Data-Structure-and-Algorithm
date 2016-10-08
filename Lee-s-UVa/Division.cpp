#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool test(int s, int t)
{
    vector<int> v(10, 0);
    if(s < 10000)
        v[0] = 1;
    while(s > 0)
    {
        v[s%10]++;
        s /= 10;
    }
    while(t > 0)
    {
        v[t%10]++;
        t /= 10;
    }
    for(int i = 0; i < v.size(); i++)
        if(v[i] != 1)
            return false;
    return true;
}

int main()
{
    int n;
    while(cin >> n)
    {
        for(int x = 1234; x <= 98765; x++)
        {
            long y = x * n;
            if(y <= 98765 && y >= 10000)
            {
                if(test(x, y))
                {
                    if(x > 10000)
                        cout << y << " / " << x << " = " << n << endl;
                    else {
                        cout << y << " / " << 0 << x << " = " << n << endl;
                    }
                }
            }
        }

    }
}
