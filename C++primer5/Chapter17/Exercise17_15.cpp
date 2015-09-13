#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);
    cout << "Please input a word! Input 'q' ot quit!" << endl;
    string s;
    while(cin >> s && s != "q")
    {
        if(regex_match(s, r))
            cout << "ok" << endl;
        else {
            cout << "is not ok" << endl;
        }
        cout << "Please enter a word and q to quit" << endl;
    }
    //smatch results;

    //string test_str = "receipt freind theif receive";
    //if(regex_search(test_str, results, r))
    //    cout << results.str() << endl;

    return 0;
}
