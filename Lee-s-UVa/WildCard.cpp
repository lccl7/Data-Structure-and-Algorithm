#include <iostream>
#include <string>
#include <vector>
using namespace std;

//DP use Memoized
bool matchMemoized(int m, int n, vector<vector<int> >& cache, string& s, string& p)
{
    int& ret = cache[m][n];
    if(ret != -1) return ret;
    if(n < p.length() && m < s.length() && (p[n] == '?' || s[m] == p[n]))
        return ret = matchMemoized(m+1, n+1, cache, s, p);
    if(n == p.length()) return ret = (m == s.length());
    if(p[n] == '*')
        if(matchMemoized(m, n+1, cache, s, p) || (m < s.length() && matchMemoized(m+1, n, cache, s, p)))
            return ret = 1;
    return ret = 0;
}

bool isMatch1(string s, string p) {
    int l = max(s.length(), p.length());
    vector<vector<int> > cache(l+1, vector<int>(l+1, -1));
    return matchMemoized(0, 0, cache, s, p);
}

bool isMatch2(string s, string p)
{
    int sLen = s.length(), pLen = p.length();
    int m = 0, n = 0, sl = 0, pl = pLen;
    while(m < sLen)
    {
        //advance both char when they match or '?' is found
        if(p[n] == '?' || s[m] == p[n])
        {
            m++; n++;
            continue;
        }
        // * found in pattern, track index of *, only advancing pattern char
        if(p[n] == '*')
        {
            pl = n++;
            sl = m;
            continue;
        }
        //current char didn't match, last pattern char was *, current pattern pointer is not *
        //only advancing pattern char
        if(pl < pLen)
        {
            n = pl + 1;
            m = ++sl;
            continue;
        }
        //characters do not match
        return false;
    }
    // check for remaining characters in pattern
    while(p[n] == '*')
        n++;
    return n == pLen;
}

int main()
{
    string s1 = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaab";
    string s2 = "a*******b";
    if(isMatch2(s1, s2))
        cout << "true" << endl;
    else {
        cout << "false" << endl;
    }
}
