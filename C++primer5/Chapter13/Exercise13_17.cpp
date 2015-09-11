#include <iostream>
using std::cout;
using std::endl;

class Numbered
{
public:
    Numbered(int my = 0): { count++; mysn = count; }
    Numbered(const Numbered &rhs) { count++; mysn = count; }
    Numbered& operator=(const Numbered &rhs) { count++; mysn = count; return *this; }

    int mysn;
    static int count;
};

int Numbered:: count = 0;

void f(Numbered s)
{
    cout << s.mysn << endl;
}

void h(Numbered &s)
{
    cout << s.mysn << endl;
}

int main()
{
    Numbered a, b = a, c = b;
    cout << a.mysn << " " << b.mysn << " " << c.mysn << endl;
    f(a); f(b); f(c);
    h(a); h(b); h(c);
    return 0;
}
