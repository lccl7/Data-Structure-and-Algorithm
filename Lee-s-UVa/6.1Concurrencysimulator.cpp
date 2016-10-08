#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::deque;
using std::queue;

const int MAX = 100;
vector<string> prog[MAX];
vector<int> tim(6, 0);
vector<int> var(MAX, 0);
vector<int> pr(MAX,0);
deque<int> dqrun;
queue<int> dqwait;
bool lock = false;
int Q = 0;

void run(int i)
{
    int rt;
    rt = Q;
    while(rt > 0)
    {
        string s = prog[i][pr[i]];
        switch(s[2])
        {
            case '=':
                {
                    rt -= tim[1];
                    int v = s[4]-'0';
                    if(s.size() == 6) v = v*10 + s[5]- '0';
                    var[s[0]-'a'] = v;
                    break;
                }
            case 'i':
                {
                    rt -= tim[2];
                    cout << i << ":" << var[s[6]-'a'] << endl;
                    break;
                }
            case 'c':
                {
                    rt -= tim[3];
                    if(lock)
                    {
                        dqwait.push(i);
                        return;
                    }
                    else {
                        lock = true;
                        break;
                    }
                }
            case 'l':
                {
                    rt -= tim[4];
                    lock = false;
                    if(!dqwait.empty())
                    {
                        int k = dqwait.front();
                        dqwait.pop();
                        dqrun.push_front(k);
                    }
                    break;
                }
            case 'd':
                {
                    return;
                }
        }
        pr[i]++;
    }
    dqrun.push_back(i);
}

int main(int argc, char *argv[])
{
    int T, n;
    ifstream infile(argv[1]);
    infile >> T;
    while(T--)
    {
        infile >> n;
        for(int i = 1; i <= 5; i++)
            infile >> tim[i];
        infile >> Q;
    }
    for(int i = 1; i <= n; i++)
    {
        string s;
        while(getline(infile, s))
        {
            if(s == "")
                continue;
            prog[i].push_back(s);
            if(prog[i].back() == "end")
                break;
        }
        dqrun.push_back(i);
    }
    while(!dqrun.empty())
    {
        int i = dqrun.front();
        dqrun.pop_front();
        run(i);
    }
    return 0;
}
