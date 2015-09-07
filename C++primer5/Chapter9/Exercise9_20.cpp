#include <list>
#include <deque>

using namespace std;

int main()
{
    deque<int> oddDeq;
    deque<int> evenDeq;
    list<int> li{1,2,3,4,5,6,7,8,9};

    for(auto i: li)
        if(i % 2)
            oddDeq.push_back(i);
        else {
            evenDeq.push_back(i);
        }

    return 0;
}
