#include <string>
#include <iostream>

using namespace std;

int main()
{
    //string Concat, s;
    //while(cin >> s)
    //    Concat += s;
    //cout << Concat << endl;

    string Separ, s;
    while(cin >> s)
        if(Separ == "")
            Separ += s;
        else {
            Separ += " " + s;
        }
    cout << Separ << endl;
}
