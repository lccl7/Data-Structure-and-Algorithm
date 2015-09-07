#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> ivec;
    for(int i = 0; i <= 100; ivec.push_back(i++));
    cout << accumulate(ivec.begin(), ivec.end(), 0) << endl;

    return 0;
}
