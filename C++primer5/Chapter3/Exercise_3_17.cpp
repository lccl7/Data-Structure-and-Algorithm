#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> svec;
    int i = 0;

    for(string s; cin >> s; svec.push_back(s));
    for(auto &s : svec)
    {
        i++;
        for(auto &c : s)
            c = toupper(c);
        cout << s << " ";
        if(i == 8)
        {
            cout << endl;
            i = 0;
        }
    }
}
