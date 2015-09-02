#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string s1 = "string", s2 = "static";
    if(s1 == s2)
        cout << "Equal" << endl;
    else {
        if(s1 > s2)
            cout << "s1 is larger!" << endl;
        else {
            cout << "s2 is larger!" << endl;
        }
    }

    const char *c1 = "string";
    const char *c2 = "static";
    auto result = strcmp(c1, c2);
    if(result > 0)
        cout << "c1 is bigger" << endl;
    else if(result == 0)
        cout << "equal" << endl;
    else {
        cout << "c2 is bigger" << endl;
    }

    return 0;
}
