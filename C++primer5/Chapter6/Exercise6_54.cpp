int func(int, int);

typedef int (*pf1)(int, int);
using pf2 = decltype(func) *;
using pf3 = int (*)(int, int);
typedef decltype(func) *pf4;
using pf5 = int(int, int);
using pf6 = decltype(func);
vector<f> vf;


