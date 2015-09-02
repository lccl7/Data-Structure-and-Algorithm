#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;

    for(int i; cin >> i; ivec.push_back(i));
    for(auto i = 0; i < ivec.size(); i += 2)
        if(i != ivec.size()-1)
            cout << ivec[i] + ivec[i+1] << " ";
        else {
            cout << ivec[i];
        }
    cout << endl;

    for(unsigned i = 0, j = ivec.size()-1; i <= j; i++, j--)
        if(i < j)
            cout << ivec[i] + ivec[j] << " ";
        else {
            cout << ivec[i];
        }
    cout << endl;

    return 0;
}
