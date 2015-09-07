#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    map<string, vector<string>> famls;

    string lastName, chldName;

    while([&]()->bool
    {
        cout << "Please enter last name:\n";
        return cin >> lastName && lastName != "@q";
    }())
    {
        cout << "PLZ Enter children's name:\n";
        while(cin >> chldName && chldName != "@q")
        {
            famls[lastName].push_back(chldName);
        }
    }

    for(auto e: famls)
    {
        cout << e.first << ":\n";

        for(auto c: e.second)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}
