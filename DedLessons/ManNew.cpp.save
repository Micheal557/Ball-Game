#include "TXLib.h"
using namespace std;

struct SBall
    {
    int x, y, vx, vy, radius;
    };

void SphereMovement ();
void DrawSphere (SBall ball);
void ParameterChange (SBall* ball, int dt);

const int Lengthwindow = 800;
      int Widthwindow = 600;


int main ()
    {
    txCreateWindow (Lengthwindow, Widthwindow);
    txTextCursor (false);
    /*int x = 20, y = 20;
    int radius = 20;

    while (x < 800)
    {
    cout << x;
        y = 20;
        while (y < 600)
        {
        DrawSphere (x, y, radius);
        y = y + 2*radius;
        }

    x = x + 2*radius;

    }*/
    SphereMovement ();
    return 0;
    }

//=============================================================================//

void SphereMovement ()
    {
    SBall ball1 = {100, 100, 5, 6, 20};
    SBall ball2 = {200, 200, 7, 8, 30};
    SBall ball3 = {300, 300, 9, 10, 40};
    SBall ball4 = {400, 400, 11, 12, 50};
    dt = 1;
    //cout <<"значение €чейки в " << __func__ << " == " << x;
    //cin.get ();
    while (!GetAsyncKeyState (VK_ESCAPE))       //сделать 3 и 4 шарик
        {
        //vx = 10;                                              исходник TXLib.h смотреть в сообщении
        txSetFillColor (TX_BLACK);
        txClear ();
        DrawSphere (ball1);
        DrawSphere (ball2);
        DrawSphere (ball3);
        DrawSphere (ball4);
        //cout <<"DrawKotik до вызова функции MovementKotik x="<< x << "  y=" << y <<" r="<< radius<< endl;
        //cin.get ();
        ParameterChange (&ball1, dt);
        ParameterChange (&ball2, dt);
        ParameterChange (&ball3, dt);
        ParameterChange (&ball4, dt);

        if (GetAsyncKeyState (VK_RIGHT))  ball1.vx++;
        if (GetAsyncKeyState (VK_LEFT))   ball1.vx--;
        if (GetAsyncKeyState (VK_UP))     ball1.vy++;
        if (GetAsyncKeyState (VK_DOWN))   ball1.vy--;
        if (GetAsyncKeyState (VK_RETURN)) ball1.vx = 0, ball1.vy = 0;
        //cout <<"DrawKotik после вызова функции MovementKotik x="<< x << "  y=" << y <<" r="<<radius<< endl;
        //cin.get ();

        txSleep (10);
        }
     }

//=============================================================================//

void DrawSphere (SBall ball)
    {

    //cout <<"значение €чейки в S"<< &x;
    //cin.get ();
    int startG = 64, finishG = 255;
    int startRadius = ball.radius, finishRadius = 2;
    double Xlight = -(ball.x - (Lengthwindow - 2*ball.radius)/2)/500.0;
    double Ylight = -(ball.y - (Widthwindow  - 2*ball.radius)/2)/500.0;

    for (int t = 0; t <= 10; t++)
        {
        txSetColor (TX_NULL);
        txSetFillColor (RGB (0, startG + t*(finishG - startG)/10.0, 0));                                          //2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
        txCircle (ball.x + Xlight*t, ball.y + Ylight*t, startRadius + (finishRadius - startRadius)*sqrt(t/10.0));
        //cout <<Xlight*t<< " "<< Ylight*t<< std::endl;
        //cin.get ();
        //t = t + 1;
        }

    }

//=============================================================================//

void ParameterChange (SBall* ball, int dt)
    {
    (*ball).x = (*ball).x + (*ball).vx*dt;
    ball->y = ball->y + ball->vy*dt;

    if (ball->x > Lengthwindow - ball->radius)
        {
        ball->vx = -ball->vx;
        ball->x = 2*(Lengthwindow - ball->radius) - ball->x;
        }

    if (ball->y > Widthwindow - ball->radius)
        {
        ball->vy = -ball->vy;
        ball->y = 2*(Widthwindow - ball->radius) - ball->y;
        }

    if (ball->x < ball->radius)
        {
        ball->vx = -ball->vx;
        ball->x = 2*(ball->radius) - ball->x;
        }

    if (ball->y < ball->radius)
        {
        ball->vy = -ball->vy;
        ball->y = 2*(ball->radius) - ball->y;
        }
    }
