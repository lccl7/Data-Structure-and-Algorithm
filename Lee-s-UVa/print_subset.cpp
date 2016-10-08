#include <iostream>
#include <vector>
using namespace std;

//print subset of a set which is {1, 2, 3 ... n}
//in the program that is from s to n
void print_subset1(int n, vector<int>& v, int cur)
{
    for(int i = 0; i < cur; i++)
        cout << v[i] << " ";
    cout << endl;
    int s = cur ? v[cur-1]+1 : 1;
    for(int i = s; i <= n; i++)
    {
        v[cur] = i;
        print_subset1(n, v, cur+1);
    }
}

void print_subset2(int n, vector<int>& B, int cur)
{
    if(cur == n)
    {
        for(int i = 0; i < cur; i++)
            if(B[i])
                cout << i << " ";
        cout << endl;
        return;
    }
    B[cur] = 1;
    print_subset2(n, B, cur+1);
    B[cur] = 0;
    print_subset2(n, B, cur+1);
}

void print_subset3(int n, int s)
{
    for(int i = 0; i < n; i++)
        if(s & (1 << i))
        {
            cout << i + 1 << " ";
        }
    cout << endl;
}

int main()
{
    vector<int> A(5, 0);
    //print_subset1(4, A, 0);
    //print_subset2(4, A, 0);
    for(int i = 0; i < (1 << 4); i++)
    {
        print_subset3(4, i);

    }
}
