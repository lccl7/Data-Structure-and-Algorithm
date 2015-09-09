#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    multimap<string, string> authorworks;

   string author, works;
   while(cin >> author >> works)
       authorworks.insert(make_pair(author, works));

   while(cin >> author)
   {
       auto iter = authorworks.find(author);
       if(iter != authorworks.end())
           authorworks.erase(iter);
   }

   return 0;
}
