#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> ivec;
    for(int i; cin >> i; ivec.push_back(i));
    cout << count(ivec.begin(), ivec.end(), 7) << endl;

    return 0;
}
