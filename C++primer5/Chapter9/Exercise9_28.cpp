#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void insertstring(forward_list<string>& fs, string s1, string s2)
{
    auto prev = fs.before_begin();
    auto curr = fs.begin();
    while(curr != fs.end())
    {
        if(*curr == s1)
        {
            fs.insert_after(curr, s2);
            return;
        }
        prev++;
        curr++;
    }
    curr == fs.end() ? fs.insert_after(prev, s2) : curr;
}

int main()
{
    forward_list<string> fs{"with", "that", "array"};
    insertstring(fs, "with", "the");
    for(auto s : fs)
        cout << s << " ";
    cout << endl;
    insertstring(fs, " what", "the");
    for(auto s : fs)
        cout << s << " ";
    cout << endl;

    return 0;
}
