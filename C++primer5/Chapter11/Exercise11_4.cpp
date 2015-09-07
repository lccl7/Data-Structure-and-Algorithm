#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

string lowcase(string& word)
{
    for(auto &c: word)
        c = tolower(c);
    word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
    return word;
}

int main(int argc, char *argv[])
{
    ifstream infile(argv[1]);
    map<string, size_t> word_count;
    set<string> exclude = { "The", "But", "And", "Or", "An", "A",
                            "the", "but", "and", "or", "an", "a"};
    string word;
    while(infile >> word)
        if(exclude.find(word) == exclude.end())
            ++word_count[lowcase(word)];
    for(const auto &w: word_count)
        cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
