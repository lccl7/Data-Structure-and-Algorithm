#include <iostream>
#include <list>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::ifstream;

int main(int argc, char **argv)
{
    ifstream infile(argv[1]);
    string s;
    while(getline(infile, s))
    {
        list<char> lc;
        list<char>::iterator iter = lc.begin();
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '[')
                iter = lc.begin();
            else if(s[i] == ']')
                iter = lc.end();
            else {
                lc.insert(iter, s[i]);
            }
        }
        for(list<char>::iterator it = lc.begin(); it != lc.end(); it++)
        {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}
