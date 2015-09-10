#include <iostream>
#include <fstream>
#include "Exercise12_19.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream infile(argv[1]);
    string line;
    StrBlob str;
    while(getline(infile, line))
        str.push_back(line);
    StrBlobPtr beg(str.begin()), end(str.end());
    while(beg != end)
    {
        cout << beg.deref() << endl;
        beg.incr();
    }

    return 0;
}
