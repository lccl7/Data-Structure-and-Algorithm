#include <iostream>
#include <string>

using namespace std;

int main()
{
    string prestr = " ", str, word;
    int times = 0, maxt = 1;
    while(cin >> str)
    {
        if(str == prestr)
        {
            times++;
        }
        else {
            times = 1;
            prestr = str;
        }
        if(times > maxt)
        {
            maxt = times;
            word = str;
        }
    }

    if(maxt > 1)
        cout << "word " << word << " occurred " << maxt << " times";
    else {
        cout << "no word was repreted" << endl;
    }
}
