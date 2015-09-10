#include <new>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string s1 = "Hello ", s2 = "World!";
    int n = s1.size() + s2.size() + 1;
    char *concat = new char[n];
    strcat(concat, "Hello ");
    strcat(concat, "World!");
    cout << concat << endl;
    delete []concat;

    string str1, str2;
    str1 = s1, str2 = s2;
    cout << str1 + str2 << endl;

    return 0;
}
