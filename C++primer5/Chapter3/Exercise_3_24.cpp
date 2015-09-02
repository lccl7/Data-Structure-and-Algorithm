#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    for(int i; cin >> i; ivec.push_back(i));

    if(ivec.empty())
        cout << "vector is empty";
    else if(ivec.size() == 1)
        cout << *ivec.begin() << " vector has no adjacent elements" ;
    else
    for(auto it = ivec.begin(); it != ivec.end(); it++)
        cout << *it + *(it+1) << " ";
    cout << endl;

    for(auto beg = ivec.begin(), end = ivec.end(); beg != end; beg++, end--)
    {
        if(beg != end)
        cout << *beg + (*end) << " ";
        else {
            cout << *beg;
        }
    }
    cout << endl;

    return 0;
}
