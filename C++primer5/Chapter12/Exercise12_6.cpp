#include <iostream>
#include <vector>
#include <new>

using namespace std;

vector<int>* factory()
{
    auto *p = new vector<int>;
    return p;
}

auto read(vector<int>* p)->vector<int>*
{
    int i;
    while(cin >> i)
        p->push_back(i);
    return p;
}

void print(vector<int>* p)
{
    for(auto n: *p)
        cout << n << " ";
    cout << endl;
}

int main()
{
    auto v = read(factory());
    print(v);
    delete v;
}
