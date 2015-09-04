#include <iostream>
using namespace std;

int main()
{
    unsigned ffCnt = 0, fiCnt = 0, flCnt = 0;
    char ch, preCh = '\0';

    while(cin >> noskipws >> ch)
    {
        switch(ch)
        {
            case 'i':
                if(preCh == 'f')
                    fiCnt++;
                break;
            case 'f':
                if(preCh == 'f')
                    ffCnt++;
                break;
            case 'l':
                if(preCh == 'f')
                    flCnt++;
                break;
        }
        preCh = ch;
    }

    cout << "Number of fi: " << fiCnt << endl;
    cout << "Number of ff: " << ffCnt << endl;
    cout << "Number of fl: " << ffCnt << endl;

    return 0;
}
