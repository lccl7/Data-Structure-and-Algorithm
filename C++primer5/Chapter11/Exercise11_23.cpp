#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    multimap<string, string> famls;

    string lastName, childName;
    while(cin >> lastName >> childName)
    {
        famls.insert({ lastName, childName });
    }

    for(auto &f: famls)
        cout << f.second << " " << f.first << endl;

    return 0;
}
