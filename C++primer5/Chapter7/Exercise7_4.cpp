#include <string>

class Person
{
private:
    string name = "Mark";
    string address = "Shanghai";
public:
    string getName() const { return name; }
    string getAdd() const { return address; }
}
