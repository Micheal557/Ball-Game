#include "TXLib.h"
using namespace std;

struct SBall
    {
    int x, y, vx, vy, radius;
    };

void SphereMovement ();
void DrawSphere (SBall ball);
void ParameterChange (int* x, int* y, int* radius, int* vx, int* vy, int dt);

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
    int radius = 20,  dt = 1;
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
        ParameterChange (&ball1.x, &ball1.y, &ball1.radius, &ball1.vx, &ball1.vy, dt);
        ParameterChange (&ball2.x, &ball2.y, &ball2.radius, &ball2.vx, &ball2.vy, dt);
        ParameterChange (&ball3.x, &ball3.y, &ball3.radius, &ball3.vx, &ball3.vy, dt);
        ParameterChange (&ball4.x, &ball4.y, &ball4.radius, &ball4.vx, &ball4.vy, dt);

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
//                  x €вл€етс€ адресом
//                  __^___
//                  |    |
void ParameterChange (int* x, int* y, int* radius, int* vx, int* vy, int dt)
    {
   /* cout <<"адрес €чейки в    " << __func__ << " == " <<  x << endl;          // &x - узнает какой адрес у переменной
    cout <<"значение €чейки в " << __func__ << " == " << *x << endl;          // *x - заходим по адресу и берем оттуда значение исходной переменной
    cout <<"адрес адреса перменной  x " << __func__ << " == " << &x << endl;
    cout <<"значение €чейки в " << __func__ << " == " << *(*(&x)) << endl; */
    //cout <<"в функции MovementKotik до пересчета х и у x="<< x << "  y=" << y <<" r=" <<radius<< endl;
    //cin.get ();
    *x = *x + *vx*dt;
    *y = *y + *vy*dt;
    //cout <<"в функции MovementKotik после пересчета х и у x="<< x << "  y=" << y << " r="<<radius<< endl;
    //cin.get ();
    if (*x > Lengthwindow - *radius)
        {
        *vx = -*vx;
        *x = 2*(Lengthwindow - *radius) - *x;
        }

    if (*y > Widthwindow - *radius)
        {
        *vy = -*vy;
        *y = 2*(Widthwindow - *radius) - *y;
        }

    if (*x < *radius)
        {
        *vx = -*vx;
        *x = 2*(*radius) - *x;
        }

    if (*y < *radius)
        {
        *vy = -*vy;
        *y = 2*(*radius) -  *y;
        }
    }
