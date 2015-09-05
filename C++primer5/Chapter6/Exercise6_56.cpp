#include <iostream>
#include <vector>

using namespace std;

int func(int, int);

typedef int (*pf1)(int, int);
using pf2 = decltype(func) *;
using pf3 = int (*)(int, int);
typedef decltype(func) *pf4;
using pf5 = int(int, int);
using pf6 = decltype(func);

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if(b)
        return a / b;
    return 0;
}

int main()
{
    vector<pf1> vf{add, subtract, multiply, divide};
    for(auto f : vf)
        cout << f(2, 2) << endl;
}
