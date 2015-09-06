#include <string>

#include <string>

class Person
{
    string name;
    string address;

public:
    string getName() const { return name; }
    string getAdd() const { return address; }
    Person() = default;
    Person(const string n, const string a):name(n), address(a) {}
    Person(istream& is){read(is, *this)}
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
