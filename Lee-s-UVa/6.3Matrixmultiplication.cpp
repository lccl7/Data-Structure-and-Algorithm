#include <iostream>
#include <stack>
#include <string>
using std::getline;
struct Matrix{
    int row, col;
    Matrix(int row1=0, int col1=0):row(row1),col(col1){}
} m[26];
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stack;

int main()
{
    int n;
    char c;
    cin >> n;
    while(n--)
    {
        cin >> c;
        int k = c - 'A';
        cin >> m[k].row >> m[k].col;
    }
    string s;
    while(cin >> s)
    {
        int len = s.length();
        stack<Matrix> stk;
        int cnt = 0;
        bool flag = true;
        for(int i = 0; i < len; i++)
        {
            if(isalpha(s[i]))
                stk.push(m[s[i]-'A']);
            else if(s[i] == ')')
            {
                Matrix m2 = stk.top(); stk.pop();
                Matrix m1 = stk.top(); stk.pop();
                if(m1.col == m2.row)
                {
                    cnt += m1.row * m1.col * m2.col;
                    stk.push(Matrix(m1.row, m2.col));
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            cout << cnt << endl;
        else {
            cout << "error" << endl;
        }
    }
    return 0;
}
