#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using std::string;
using std::ifstream;
using std::stringstream;
using std::vector;
using std::queue;
using std::cout;
using std::endl;

int flag = 1;

struct Node
{
    bool IsValue;
    int v;
    Node *left, *right;
    Node():IsValue(false), left(NULL), right(NULL) {}
};

Node *root = NULL;
Node *newnode()
{
    return new Node();
}

void addnode(int v, string s)
{
    int len = s.length();
    Node *u = root;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == 'L')
        {
            if(u->left == NULL)
                u->left = newnode();
            u = u->left;
        }
        else if(s[i] == 'R')
        {
            if(u->right == NULL)
                u->right = newnode();
            u = u->right;
        }
    }
    if(u->IsValue)
        flag = 0;
    u->v = v;
    u->IsValue = true;
}

int stoi(string s)
{
    int n = s.length();
    int sum = 0;
    for(int j = 0; j < n; j++)
        sum = sum*10 + s[j]-'0';
    return sum;
}

string s;
bool read_input(ifstream &input)
{
    string inputstring;
    if(!input.eof())
        getline(input, inputstring);
    flag = 1;
    root = newnode();
    while(1)
    {
        string::size_type i = inputstring.find('(');
        string::size_type j = inputstring.find(')');
        if(i == string::npos)
            return false;
        if(j != string::npos)
        {
            s = inputstring.substr(i, j-i+1);
            inputstring = inputstring.substr(j+1);
        }
        else {
            s = inputstring.substr(i, inputstring.length());
        }
        if(s == "")
            return false;
        if(s == "()")
            break;
        int v;
        string::size_type pos = s.find(',');
        v = stoi(s.substr(1, pos-1));
        addnode(v, s.substr(pos+1));
    }
    return true;
}

bool bfs(vector<int> &ans)
{
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty())
    {
        Node* u = q.front();
        q.pop();
        if(!u->IsValue)
            return false;
        ans.push_back(u->v);
        if(u->left)
            q.push(u->left);
        if(u->right)
            q.push(u->right);
    }
    return true;
}

int main(int argc, char **argv)
{
    ifstream infile(argv[1]);
    vector<int> ans;
    while(read_input(infile))
    {
        if(!bfs(ans))
            flag = 0;
        if(flag == 0)
            cout << "not complete" << endl;
        else
        {
            for(int i = 0; i < ans.size(); i++)
            {
                if(i == ans.size()-1)
                    cout << ans[i] << " " << endl;
                else
                    cout << ans[i] << " ";
            }
        }
    }

    return 0;
}
