#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    const char *a1 = "Hello";
    const char *b1 = "World";

    int len = strlen(a1) + strlen(b1) +  strlen(" ") + 1;
    char c[len];
    strcpy(c, a1);
    strcat(c, " ");
    strcat(c, b1);
    const char *cp = c;
    cout << c << endl;

    return 0;
}
