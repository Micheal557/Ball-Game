#include "TXLib.h"

void MoveBall ();
void Grafica (int x, int y);

int main ()
    {
    txCreateWindow (800, 600);

    MoveBall ();
    return 0;
    }

//=============================================================================

void MoveBall ()
    {
    int x = 0, y = 0;
    int vx = 5, vy = 6;
    int dt = 1;

    while (true)
        {
        Grafica (x, y);

        x = x + vx*dt;
        y = y + vy*dt;

        if (x > 800)
            {
            vx = -vx;
            x = 800;
            }

        if (x < 0)
            {
            vx = -vx;
            x = 0;
            }

        if (y > 600)
            {
            vy = -vy;
            y = 600;
            }

        if (y < 0)
            {
            vy = -vy;
            vy = 0;
            }

        txSleep (100);

        }
    }

//=============================================================================

void Grafica (int x, int y)
    {
    txSetColor (TX_GREEN);
    txCircle (x, y, 20);
    }





