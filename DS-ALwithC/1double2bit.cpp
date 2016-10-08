#include <iostream>
#include <string>
using namespace std;

string int2str(int n)
{
    string s;
    while(n > 0)
    {
        char c = n % 2 + '0';
        s = c + s;
        n /= 2;
    }
    return s;
}

string fra2str(double n)
{
    string s;
    while(n > 0.0)
    {
        if(s.length() > 32)
            return "ERROR";
        n *= 2;
        if(n >= 1.0)
        {
            s += '1';
            n -= 1.0;
        }
        else {
            s += '0';
        }
    }
    return s;
}

int main()
{
    string d = "3.5";
    int d1 = d.find('.');
    string n = d.substr(0, d1);
    cout << n << endl;
    string n2 = d.substr(d1);
    cout << n2 << endl;
    //while(cin >> n)
    //    cout << int2str(n) << endl;
    //while(cin >> d)
    //    cout << fra2str(d) << endl;
}
