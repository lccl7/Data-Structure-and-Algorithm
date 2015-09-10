#include <iostream>
#include <new>
#include <string>

using namespace std;

int main()
{
    int size(0);
    cin >> size;
    char *variedInput = new char[size+1];
    cin.ignore();
    string s;
    cin.get(variedInput, size+1);
    cout << variedInput << endl;
    delete []variedInput;

    return 0;
}
