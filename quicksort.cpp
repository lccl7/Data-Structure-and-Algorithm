#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stack>
using namespace std;

template <class T>
int Partition(vector<T> &data, int lo, int hi)
{
    T v = data[lo];
    while(lo < hi)
    {
        while(lo < hi && data[hi] >= v)
            hi--;
        data[lo] = data[hi];
        while(lo < hi && data[lo] <= v)
            lo++;
        data[hi] = data[lo];
    }
    data[lo] = v;
    return lo;
}

template <class T>
void quicksort1(vector<T> &data, int p, int r)
{
    if(p < r)
    {
        int q = Partition(data, p, r);
        quicksort1(data, p, q-1);
        quicksort1(data, q+1, r);
    }
}

template <class T>
void quicksort2(vector<T> &data, int lo, int hi)
{
    stack<int> st;
    int m;
    if(lo < hi)
    {
        m = Partition(data, lo, hi);
        if(lo < m-1)
        {
            st.push(lo);
            st.push(m-1);
        }
        if(m+1 < hi)
        {
            st.push(m+1);
            st.push(hi);
        }
    }
    while(!st.empty())
    {
        int q = st.top();
        st.pop();
        int p = st.top();
        st.pop();
        m = Partition(data, p, q);
        if(p < m-1)
        {
            st.push(p);
            st.push(m-1);
        }
        if(m+1 < q)
        {
            st.push(m+1);
            st.push(q);
        }
    }
}

int main()
{
    int len = 1000000;
    vector<int> vi;
    for(int i = 0; i < len; i++)
        vi.push_back(rand());
    //for(int i = 0; i < vi.size(); i++)
    //{
     //   if(i % 10 == 0)
      //      cout << endl;
       // cout << vi[i] << " ";
    //}
    clock_t t1 = clock();
    quicksort1(vi, 0, vi.size()-1);
    clock_t t2 = clock();
    cout << endl;
   // for(int i = 0; i < vi.size(); i++)
    //{
     //   if(i % 10 == 0)
      //      cout << endl;
       // cout << vi[i] << " ";
    //}
    cout << "recursive time: " << 1.0*(t2 - t1)/CLOCKS_PER_SEC << endl;

    cout << endl;
    random_shuffle(vi.begin(), vi.end());
    //for(int i = 0; i < vi.size(); i++)
    //{
     //   if(i % 10 == 0)
      //      cout << endl;
       // cout << vi[i] << " ";
   // }
    cout << endl;
    t1 = clock();
    quicksort2(vi, 0, vi.size()-1);
    t2 = clock();
    //for(int i = 0; i < vi.size(); i++)
    //{
     //   if(i % 10 == 0)
      //      cout << endl;
       // cout << vi[i] << " ";
    //}
    cout << "non-recursive time: " << 1.0*(t2-t1)/CLOCKS_PER_SEC << endl;

    return 0;
}
