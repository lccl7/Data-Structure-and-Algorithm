HasPtr
{
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &rhs):i(rhs.i), *ps = new string(*rhs.ps) { }
private:
    string *ps;
    int i;
}
