#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}

void print(vector<string>& words)
{
    for(auto s: words)
        cout << s << " ";
    cout << endl;
}

int main()
{
    vector<string> words{"fox", "jumps", "over", "quick", "the", "slow", "red", "turtle", "the", "red"};

    print(words);
    sort(words.begin(), words.end());
    print(words);
    auto end_unique = unique(words.begin(), words.end());
    print(words);
    words.erase(end_unique, words.end());
    print(words);
    stable_sort(words.begin(), words.end(), isShorter);
    print(words);

    return 0;
}
