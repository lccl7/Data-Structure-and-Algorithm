#include <iostream>
#include <vector>

using namespace std;

struct X
{
    X() { cout << "X()" << endl; }
    X(const X&) { cout << "X(const X&)" << endl; }
    X& operator=(const X &rhs) { cout << "X=(const X&)" << endl; return *this; }
    ~X() { cout << "~X()" << endl; }
};

void f(const X &rx, X x)//copy once
{
    vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);//copy
    vec.push_back(x);//copy
}// destructor in vec

int main()
{
    X *x = new X;//constructor
    X y(*x), z;//copy constructor, constructor
    z = *x;    //assignment constructor
    //vector<X> vec;
    //vec.push_back(*x);//copy constructor
    f(*x, *x);
    delete x;
}// destructor in vec, y, z
