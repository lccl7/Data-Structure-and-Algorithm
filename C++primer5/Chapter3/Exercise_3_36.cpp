#include <vector>
#include <iostream>

using namespace std;

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size], ib[array_size];

    if((end(ia) - begin(ia)) != (end(ib) - begin(ib)))
        cout << "Not Equal!" << endl;
    else {
        for(auto a = begin(ia), b = begin(ib); a != end(ia); a++, b++)
            if(*a == *b)
            {
                continue;
            }
            else
                break;
        cout << "Equal!" << endl;
    }

    vector<int> ivec1(10), ivec2(10);
    if(ivec1 != ivec2)
        cout << "Not Equal!" << endl;
    else {
        cout << "Equal!" << endl;
    }

    return 0;
}
