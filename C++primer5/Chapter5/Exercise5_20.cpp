#include <iostream>
#include <string>

using namespace std;

int main()
{
    string pre = " ", str;
    bool flag = false;
    while(cin >> str)
    {
        if(str == pre)
        {
            flag = true;
            break;
        }
        else {
            pre = str;
        }
    }
    if(flag)
        cout << str << " occurs twice in succession" << endl;
    else {
        cout << "no word was repeated" << endl;
    }

    return 0;
}
