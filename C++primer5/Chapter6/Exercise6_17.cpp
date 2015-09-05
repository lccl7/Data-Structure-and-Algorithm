#include <iostream>
#include <string>
#include <cctype>

bool anyLetterCapitial(const string& s)
{
    for(auto c : s)
        if(isupper(c))
            return true;
    return false;
}

string& changeLowerCase(string& s)
{
    for(auto &c : s)
        c = tolower(c);
    return s;
}
