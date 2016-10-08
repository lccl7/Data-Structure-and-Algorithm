//Test case for input:
//1
//10
//1 2
//2 4
//5 8
//6 10
//7 9
//3 1
//5 8
//12 10
//9 7
//2 2
//Output: 5
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 1000;
int G[maxn][maxn], d[maxn], T;

struct Rect
{
    int length, width;
    Rect():length(0), width(0){}
    Rect(int l, int w): length(l), width(w){}
};

int dp(int i)
{
    int& ans = d[i];
    if(ans > 0) return ans;
    ans = 1;
    for(int j = 0; j < T; j++)
        if(G[i][j])
            ans = max(ans, dp(j) + 1);
    return ans;
}

void print_ans(int i)
{
    for(int j = 0; j < T; j++)
        if(G[i][j] && d[i] == d[j]+1)
        {
            print_ans(j);
         //   break;
        }
    cout << i << " ";
}

int main(int argc, char** argv)
{
    ifstream infile(argv[1]);
    int group;
    infile >> group >> T;
    vector<Rect> v(T+1);
    for(int n = 0; n < T; n++)
    {
        int length, width;
        infile >> length >> width;
        v[n] = Rect(length, width);
        cout << n << ":" << v[n].length << "," << v[n].width << endl;
    }
    for(int i = 0; i < T; i++)
        for(int j = 0; j < T; j++)
        {
            if((v[i].length > v[j].length && v[i].width > v[j].width)||
                (v[i].width > v[j].length && v[i].length > v[j].width))
            {
                G[i][j] = 1;
            }
        }
    for(int i = 0; i < T; i++)
    {
        for(int j = 0; j < T; j++)
            cout << G[i][j] << " ";
        cout << endl;
    }
    int answer = -1, t, s;
    for(int i = 0; i < T; i++)
    {
        t = dp(i);
        if(answer < t)
        {
            answer = t;
            s = i;
        }
    }
    cout << answer << endl;
    print_ans(s);
    cout << endl;
}
