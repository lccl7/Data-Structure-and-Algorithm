#include <deque>
#include <string>

using namespace std;

int main()
{
    string s;
    list<string> ls;
    while(cin >> s)
        ls.push_back(s);
    for(auto beg = ls.begin(); beg != ls.end(); beg++)
        cout << *beg << endl;

    return 0;
}
