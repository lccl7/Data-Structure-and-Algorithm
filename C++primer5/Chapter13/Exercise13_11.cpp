HasPtr
{
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &rhs):i(rhs.i), ps(new string(*rhs.ps)) { }
    HasPtr& operator=(HasPtr &rhs)
    {
        i = rhs.i;
        string *p = new string(*rhs.ps);
        delete ps;
        ps = p;
        *ps = *rhs.ps;
        return *this;
    }
    ~HasPtr() { delete ps; }

private:
    string *ps;
    int i;
}
