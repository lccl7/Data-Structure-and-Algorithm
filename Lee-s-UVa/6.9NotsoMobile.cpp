#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
bool solve(ifstream &infile);

int main(int argc, char** argv)
{
    ifstream infile(argv[1]);
    int T;
    infile >> T;
    while(T--)
    {
        if(solve(infile)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

bool solve(ifstream &infile)
{
    int W1, D1, W2, D2;
    bool b1 = true, b2 = true;
    infile >> W1 >> D1 >> W2 >> D2;
    if(!W1) b1 = solve(infile);
    if(!W2) b2 = solve(infile);
    return b1 && b2 && (W1*D1 == W2*D2);
}
