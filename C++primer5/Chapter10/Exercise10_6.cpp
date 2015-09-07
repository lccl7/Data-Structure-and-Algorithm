#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int array[] = {1, 2, 3, 4};
    for(auto beg = begin(array); beg != end(array); beg++)
        cout << *beg << " ";
    cout << endl;

    fill_n(begin(array), end(array) - begin(array), 0);
    for(auto beg = begin(array); beg != end(array); beg++)
        cout << *beg << " ";
    cout << endl;

    return 0;
}
