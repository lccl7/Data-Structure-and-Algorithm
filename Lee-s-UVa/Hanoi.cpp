#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C)
{
    if(n == 1)
        cout << n << " from " << A << " to " << C << endl;
    else {
        hanoi(n-1, A, C, B);
        cout << n << " from " << A << " to " << C << endl;
        hanoi(n-1, B, A, C);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    hanoi(n, 'A', 'B', 'C');
}
