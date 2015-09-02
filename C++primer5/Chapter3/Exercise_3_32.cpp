#include <iostream>
#include <vector>

using namespace std;

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    int ib[array_size];
    for(size_t ix = 0; ix < array_size; ix++)
        ia[ix] = ix;
    for(size_t ix = 0; ix < array_size; ix++)
        ib[ix] = ia[ix];
    return 0;
}
