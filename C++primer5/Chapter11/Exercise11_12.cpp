#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<pair<string, int>> vp;

    string s;
    int i;
    while(cin >> s >> i)
        vp.push_back({s, i});

    for(auto c : vp)
        cout << c.first << ": " << c.second << endl;

    return 0;
}
