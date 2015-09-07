#include <vector>

bool isFound(vector<int>::iterator iter1, vector<int>::iterator iter2, int value)
{
    for(auto iter = iter1; iter != iter2; iter++)
        if(*iter == value)
            return true;
    return false;
}
