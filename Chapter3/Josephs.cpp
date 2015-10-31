#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

struct node
{
    int item;
    node* next;
    node(int x, node *t): item(x), next(t) { }
};

typedef node *link;

int Josephus1(int m, int n)
{
    link t = new node(1, 0);
    t->next = t;
    link x = t;
    for(int i = 2; i <= n; i++)
        x = (x->next = new node(i, t));
    while(x != x->next)
    {
        for(int i = 1; i < m; i++)
            x = x->next;
        x->next = x->next->next;
    }
    return x->item;
}

void Josephus2(int m, int n)
{
    //use STL list<int>
}

int main(int argc, char *argv[])
{
    int m, n;
    cin >> m >> n;
    cout << Josephus1(m, n) << endl;

    return 0;
}
