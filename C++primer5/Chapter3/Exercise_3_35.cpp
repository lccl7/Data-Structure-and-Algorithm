#include <iostream>

using namespace std;

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    int *p = ia;
    for(int i = 0; i != array_size; i++)
        *(p + i) = 0;

    for(int i = 0; i != array_size; i++)
        cout << ia[i] << " ";
    cout << endl;

    return 0;
}
