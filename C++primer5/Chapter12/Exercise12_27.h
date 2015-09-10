#ifndef CP5_Ex12_30_h
#define CP5_Ex12_30_h

#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

using std::vector;
using std::map;
using std::set;
using std::vector;
using std::string;
using std::shared_ptr;
using std::ifstream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class QueryResult;
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
    friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f):
                sought(s), lines(p), file(f) { }

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream& print(ostream&, const QueryResult&);
#endif
