#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    for(int i = 0, num; i != 10 && cin >> num; i++)
    {
        ivec.push_back(num);
    }

    for(auto it = ivec.begin(); it != ivec.end(); it++)
        *it *= 2;
    for(auto i: ivec)
        cout << i << " ";
    cout << endl;

    return 0;
}
