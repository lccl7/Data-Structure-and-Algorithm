#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
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

    return 0;
}
