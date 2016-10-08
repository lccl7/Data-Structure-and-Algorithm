//For example the push schedule is {1,2,3,4,5}, test whether
//another schedule is a pop schedule, such as {4, 5, 3, 2, 1} , {4, 5, 2, 1, 3}
bool isPopSeries(string &push, string &pop)
{
    int n = push.length();
    stack<char> helper;

    int i1 = 0, i2 = 0;
    while(i2 < n)
    {
        while(helper.empty() || helper.top() != pop[i2])
        {
            if(i1 < n)
                helper.push(push[i1++]);
            else {
                return false;
            }
        }
        while(!helper.empty() && helper.top() == pop[i2])
        {
            helper.pop();
            i2++;
        }
    }
    return true;
}
