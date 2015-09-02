#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> text;
    for(string s; getline(cin, s); text.push_back(s));

    for(auto it = text.begin(); it != text.end() && !it->empty(); it++)
    {
        for(auto &c : *it)
            c = toupper(c);
        cout << *it << endl;
    }

    return 0;
}
