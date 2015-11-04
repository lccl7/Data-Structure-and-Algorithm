#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void partitionArray(vector<int>& nums, int k)
{
    if(nums.size() == 0) return;
    int i = -1, j = 0;
    while(j < nums.size())
    {
        if(nums[j] < k)
        {
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }
}

int main()
{
    int A[] = {3, 2, 2, 1};
    vector<int> nums;
    nums.assign(A, A + 4);
    partitionArray(nums, 2);
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
