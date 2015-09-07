#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream infile(argv[1]);
    map<string, size_t> word_count;
    set<string> exclude = { "The", "But", "And", "Or", "An", "A",
                            "the", "but", "and", "or", "an", "a"};
    string word;
    while(infile >> word)
        if(exclude.find(word) == exclude.end())
            ++word_count[word];
    for(const auto &w: word_count)
        cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}
