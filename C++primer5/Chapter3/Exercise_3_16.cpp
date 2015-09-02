#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "v1.size() = " << v1.size() << ": ";
    if(v1.size() > 0)
    {
        for(auto i : v1)
            cout << i << ",";
        cout << '\b' << endl;
    }
    else {
        cout << "empty" << endl;
    }

    cout << "v2.size() = " << v2.size() << ": ";
    if(v2.size() > 0)
    {
        for(auto i : v2)
            cout << i << ",";
        cout << '\b' << ' ' << endl;
    }
    else {
        cout << "empty" << endl;
    }

    cout << "v3.size() = "<< v3.size() << ": ";
    if(v3.size() > 0)
    {
        for(auto i : v3)
            cout << i << ",";
        cout << '\b' << ' ' << endl;
    }
    else {
        cout << "empty" << endl;
    }

    cout << "v4.size() = " << v4.size() << ": ";
    if(v4.size() > 0)
    {
        for(auto i : v4)
            cout << i << ",";
        cout << '\b' << ' ' << endl;
    }
    else {
        cout << "empty" << endl;
    }

    cout << "v5.size() = " << v5.size() << ": ";
    if(v5.size() > 0)
    {
        for(auto i : v5)
            cout << i << ",";
        cout << '\b' << ' ' << endl;
    }
    else {
        cout << "empty" << endl;
    }

    cout << "v6.size() = " << v6.size() << ": ";
    if(v6.size() > 0)
    {
        for(auto s : v6)
            if(s.empty())
                cout << "null" << ",";
            else {
                cout << s << ",";
            }
        cout << '\b' << ' ' << endl;
    }
    else {
        cout << "empty" << endl;
    }

    cout << "v7.size() = " << v7.size() << ": ";
    if(v7.size() > 0)
    {
        for(auto i : v7)
            cout << i << ",";
        cout << '\b' << ' ' << endl;
    }
    else {
        cout << "empty" << endl;
    }
}
