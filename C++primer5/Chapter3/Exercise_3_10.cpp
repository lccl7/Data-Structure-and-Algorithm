#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string strpun;
    cin >> strpun;
    for(auto c : strpun)
        if(!ispunct(c))
            cout << c;
    cout << endl;

    return 0;
}
