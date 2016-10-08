#include "Heap.h"
#include "Heap.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    MaxHeap<int> mh = MaxHeap<int>(10);
    vector<int> v = { 2, 5, 7, 8, 1, 20, 9, 30, 10, 4};
    for(auto i: v)
        mh.Insert(i);
    mh.Output();
    while(mh.Size() > 0)
    {
        int x = mh.Max();
        cout << x << " ";
        mh.DeleteMax(x);
    }
    cout << endl;
}
