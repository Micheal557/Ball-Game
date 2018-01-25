#include "TXLib.h"
using namespace std;

void Summa (int x, int y);

int main ()
    {
    int x = 10, y = 15;
    Summa (x , y);
    //cout << x + y << endl;
    x = 23, y = 20;
    Summa (x, y);
    //cout << x + y << endl;
    x = 50, y = 70;
    Summa (x, y);
    //cout << x + y << endl;
    return 0;
    }

//=============================================================================

void Summa (int x, int y)
    {
    cout << x + y << endl;
    }
