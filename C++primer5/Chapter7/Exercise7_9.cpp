#include <string>

class Person
{
    string name;
    string address;

public:
    string getName() const { return name; }
    string getAdd() const { return address; }
}

istream& read(istream& is, Person& p)
{
    is >> p.name >> p.address;
    return is;
}

ostream& print(ostream& os, Person& p)
{
    os << p.name << " " << p.address;
    return os;
}
