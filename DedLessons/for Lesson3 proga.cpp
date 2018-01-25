using namespace std;
#include <iostream>
#include "TXLib.h"

void MoveKotik ();
void Sphere (int x, int y, double radius);

const int Lengthwindow = 800;
      int Widthwindow = 600;


int main()
    {
    //const int Lengthwindow = 800;
      //    int Widthwindow = 600;

    txCreateWindow (Lengthwindow, Widthwindow);
    MoveKotik ();

    return 0;
    }

//=============================================================================

void MoveKotik ()
    {
    int x = 100, y = 500;
    int vx = 5, vy = 7;
    int dt = 1, radius = 20;

    txSetColor (TX_CYAN, 1);
    txSetFillColor (TX_SATURATION);

    while (true)
        {
        Sphere (x, y, radius);

        x = x + vx*dt;
        y = y + vy*dt;

        if (x > Lengthwindow - radius)
            {
            txSetColor (TX_PINK, 3);
            txSetFillColor (TX_LIGHTGREEN);
            vx = -vx;
            x = 2*(Lengthwindow - radius) - x;
            }

        if (y > Widthwindow - radius)
            {
            txSetColor (TX_CYAN, 1);
            txSetFillColor (TX_SATURATION);
            vy = -vy;
            y = 2*(Widthwindow - radius) - y;
            }

        if (x < radius)
            {
            txSetColor (TX_PINK, 3);
            txSetFillColor (TX_LIGHTGREEN);
            vx = -vx;
            x = 2*radius - x;
            }

        if (y < radius)
            {
            txSetColor (TX_PINK, 3);
            txSetFillColor (TX_LIGHTGREEN);
            vy = -vy;
            y = 2*radius -  y;
            }

        cout << x << "   " << y << endl;
        txSleep (100);
        }
    }

//=============================================================================
    void Sphere (int x, int y, double radius)
        {
        int t = 0;
        while (t <= 10)
            {
            txSetColor (RGB (255, 0, 0));

            txCircle (x, y, radius);
            t = t + 1;
            }
        }
