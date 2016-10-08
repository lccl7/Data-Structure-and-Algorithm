#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using std::ifstream;
using std::cout;
using std::endl;
using std::queue;
using std::string;
const int MAX = 100;

int main(int argc, char** argv)
{
    ifstream infile(argv[1]);
    queue<char> quech[MAX];
    string s;
    while(getline(infile, s))
    {
        bool last = true;
        int n = s.length();
        int cur = 1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '[')
            {
                last = false;
            }
            else if(s[i] == ']')
            {
                last = true;
                cur++;
            }
            else if(last)
            {
                quech[0].push(s[i]);
            }
            else {
                quech[cur].push(s[i]);
            }
        }
        while(cur > -1)
        {
            while(!quech[cur].empty())
            {
                cout << quech[cur].front();
                quech[cur].pop();
            }
            cur--;
        }
        cout << endl;
    }
    return 0;
}
