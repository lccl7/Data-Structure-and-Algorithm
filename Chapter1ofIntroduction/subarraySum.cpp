vector<int> subarraySum(vector<int> nums)
{
    vector<int> vi;
    map<int, int> nums2index;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(nums[i] == 0)
        {
            vi.push_back(i);
            vi.push_back(i);
            return vi;
        }
        else if(sum == 0)
        {
            vi.push_back(0);
            vi.push_back(i);
            return vi;
        }
        else if(nums2index.count(sum))
        {
            vi.push_back(nums2index[sum] + 1);
            vi.push_back(i);
            return vi;
        }
        nums2index[sum] = i;
    }
    return vi;
}

vector<int> subarraySum(vector<int> nums)
{
    vector<int> vi;
    for(int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if(sum == 0)
            {
                vi.push_back(i);
                vi.push_back(j);
                return vi;
            }
        }
        return vi;
    }
}
