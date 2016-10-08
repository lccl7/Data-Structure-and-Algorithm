#include <iostream>
#include <stack>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::vector;

int main()
{
    int n;
    while(cin >> n && n)
    {
        vector<int> outRails(n+1,0);
        stack<int> helper;
        int in = 1, out = 1;
        for(int i = 1; i <= n; i++)
            cin >> outRails[i];
        bool isSequence = true;
        while(out <= n)
        {
            if(in == outRails[out])
            {
                in++;
                out++;
            }
            else if(!helper.empty() && outRails[out] == helper.top())
            {
                helper.pop();
                out++;
            }
            else if(in <= n)
                helper.push(in++);
            else {
                isSequence = false;
                break;
            }
        }
        cout << (isSequence ? "Yes":"No") << endl;
    }
    return 0;
}
