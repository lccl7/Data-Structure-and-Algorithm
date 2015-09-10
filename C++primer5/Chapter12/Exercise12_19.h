#ifndef CP5_Ex12_19_h
#define CP5_Ex12_19_h

#include <string>
#include <vector>
#include <memory>
#include <exception>
#include <initializer_list>
using std::string;
using std::vector;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::size_t;
using std::runtime_error;
using std::out_of_range;
using std::initializer_list;

class StrBlobPtr;

class StrBlob
{
    typedef vector<string>::size_type size_type;
    friend class StrBlobPtr;
public:
    StrBlob(): data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il):
        data(make_shared<vector<string>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string& t) { data->push_back(t); }
    void pop_back() { check(0, "pop_back on empty StrBlob"); data->pop_back(); };

    string& front() { check(0, "front on empty StrBlob");  return data->front(); };
    string& back() { check(0, "back on empty StrBlob"); return data->back(); };

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string& msg) const;
};

void StrBlob::check(size_t i, const string& msg) const
{
    if(i >= data->size())
        throw out_of_range(msg);
}

class StrBlobPtr
{
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz) {}
    string& deref() const;
    StrBlobPtr& incr();
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
#endif
