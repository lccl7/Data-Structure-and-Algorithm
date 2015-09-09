#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream infile(argv[1]);

    map<string, size_t> word_count;
    string word;
    while(infile >> word)
    {
        auto ret = word_count.insert({ word, 1});
        if(!ret.second)
            ++ret.first->second;
    }

    for(auto &w: word_count)
        cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times" : " time") << endl;
}
