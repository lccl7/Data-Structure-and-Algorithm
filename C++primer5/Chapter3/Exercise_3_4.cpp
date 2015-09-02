#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {
        if(str1 == str2)
            cout << "Equal" << endl;
        else if(str1 > str2)
            cout << "str1 is larger" << endl;
        else {
            cout << "str2 is larger" << endl;
        }"
    }
    while(cin >> str1 >> str2)
    {
        if(str1.size() == str2.size())
            cout << "Equal" << endl;
        else if(str1.size() > str2.size())
            cout << "str1 is larger" << endl;
        else {
            cout << "str2 is larger" << endl;
        }"
    }
}
