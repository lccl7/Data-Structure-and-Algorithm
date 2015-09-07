#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<string> svec;
    for(string s; cin >> s; svec.push_back(s));
    cout << count(svec.begin(), svec.end(), "iter") << endl;

    return 0;
}
