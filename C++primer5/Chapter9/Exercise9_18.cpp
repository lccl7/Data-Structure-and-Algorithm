#include <deque>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s;
    deque<string> ds;
    while(cin >> s)
        ds.push_back(s);
    for(auto beg = ds.begin(); beg != ds.end(); beg++)
        cout << *beg << endl;

    return 0;
}
