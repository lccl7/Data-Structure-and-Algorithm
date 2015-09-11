#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee() { number++; id = number; }
    Employee(const string n): name(n) { number++; id = number; }
private:
    string name;
    int id;
    static int number;
};

int Employee::number = 1;

int main()
{
    return 0;
}
