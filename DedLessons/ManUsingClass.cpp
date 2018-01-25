#include "TXLib.h"
using namespace std;

struct CBall
    {
    int x, y, vx, vy, radius;

    void Draw () const;                                 // доработать до полноценной игры
    void Physics (int dt);
    void Control ();
    };

void SphereMovement ();
double Length (CBall ball1, CBall ball2);
int Collision (CBall* ball1, CBall* ball2);
void Heart (int k);                                              //d*d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)
                                              //d = sqrt ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
const int Lengthwindow = 800;
      int Widthwindow = 600;


int main ()
    {
    //cout << Length (10, 10, 20, 20);
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
    int k = 5;
    Heart (k);
    cin.get ();

    CBall ball1 = {100, 100, 5, 6, 20};
    CBall ball2 = {200, 200, 7, 8, 30};
    CBall ball3 = {300, 300, 9, 10, 40};
    CBall ball4 = {400, 400, 11, 12, 50};
    int radius = 20,  dt = 1;
    //cout <<"значение €чейки в " << __func__ << " == " << x;
    //cin.get ();
    while (!GetAsyncKeyState (VK_ESCAPE))       //сделать 3 и 4 шарик
        {
        //vx = 10;                                              исходник TXLib.h смотреть в сообщении
        txSetFillColor (TX_BLACK);
        txClear ();
        ball1.Draw ();
        ball2.Draw ();
        ball3.Draw ();
        ball4.Draw ();
        //cout <<"DrawKotik до вызова функции MovementKotik x="<< x << " y=" << y <<" r="<< radius << endl;
        //cin.get ();
        //ParameterChange (&ball1, dt);      //синтаксис структуры
        ball1.Physics (dt);                  //синтаксис класса
        ball2.Physics (dt);
        ball3.Physics (dt);
        ball4.Physics (dt);

        if (Length (ball1, ball2) <= ball1.radius + ball2.radius)
            {


            txMessageBox ("ой ой ой", "окружности пересекаютс€", MB_ICONERROR);
            k--;
            if (k == 0)
                {
                txMessageBox ("хах, сегодн€ не твой день", "все заново", MB_ICONERROR);
                break;
                }
            Heart (k);

            }

        ball1.Control ();

        //Length (ball1.x, 1ball1.y, ball2.x, ball2.y);
        cout << Length (ball1, ball2) << endl;
        Collision (&ball1, &ball2);
        Collision (&ball1, &ball3);
        Collision (&ball1, &ball4);
        Collision (&ball2, &ball3);
        Collision (&ball2, &ball4);
        Collision (&ball3, &ball4);
        //cout <<"DrawKotik после вызова функции MovementKotik x="<< x << " y=" << y <<" r="<< radius << endl;
        //cin.get ();

        txSleep (10);
        }
     }

//=============================================================================// сделать счет, проигрыши и выигрыши

void CBall::Draw () const
    {                                          // не€вный параметр указывающий на текущий объект, при вызове указываетс€ не в скобках, а слева от имени ф-и через стрелку или точку
    //cout <<"значение €чейки в S"<< &x;       //   |
    //cin.get ();                              // _____
    int startG = 64, finishG = 255;            // |   |
    int startRadius = radius, finishRadius = 2;
    double Xlight = -(this->x - (Lengthwindow - 2*this->radius)/2)/500.0;
    double Ylight = -(y - (Widthwindow  - 2*radius)/2)/500.0;

    for (int t = 0; t <= 10; t++)
        {
        txSetColor (TX_NULL);
        txSetFillColor (RGB (0, startG + t*(finishG - startG)/10.0, 0));                                          //2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
        txCircle (x + Xlight*t, y + Ylight*t, startRadius + (finishRadius - startRadius)*sqrt(t/10.0));
        //cout <<Xlight*t<< " "<< Ylight*t<< std::endl;
        //cin.get ();
        //t = t + 1;
        }

    }

//=============================================================================//

void CBall::Physics (int dt)
    {
    x = x + vx*dt;
    y = y + vy*dt;

    if (x > Lengthwindow -radius)
        {
        vx = -vx;
        x = 2*(Lengthwindow - radius) - x;
        }

    if (y > Widthwindow - radius)
        {
        vy = -vy;
        y = 2*(Widthwindow - radius) - y;
        }

    if (x < radius)
        {
        vx = -vx;
        x = 2*(radius) - x;
        }

    if (y < radius)
        {
        vy = -vy;
        y = 2*(radius) - y;
        }
    }

//=============================================================================

void CBall::Control ()
    {
    if (GetAsyncKeyState (VK_RIGHT))  this->vx++;
    if (GetAsyncKeyState (VK_LEFT))   this->vx--;
    if (GetAsyncKeyState (VK_UP))     this->vy++;
    if (GetAsyncKeyState (VK_DOWN))   this->vy--;
    if (GetAsyncKeyState (VK_RETURN)) this->vx = 0, this->vy = 0;

    }

//=============================================================================

double Length (CBall ball1, CBall ball2)
    {

    double d = 0;
    d = sqrt ((ball2.x-ball1.x)*(ball2.x-ball1.x) + (ball2.y-ball1.y)*(ball2.y-ball1.y));
    return d;
    }

//=============================================================================

int Collision (CBall* ball1, CBall* ball2)
    {
    if (Length (*ball1, *ball2) <= ball1->radius + ball2->radius)
        {
        double change = ball2->vx;
        ball2->vx = ball1->vx;
        ball1->vx = change;

        std::swap (ball1->vy, ball2->vy);

        return 1;
        }

    else
        return 0;
    }
                                                                                     //384, 350
//=============================================================================

void Heart (int k)
    {
    HDC Heart = txLoadImage("Heart.bmp");
    int i = 1;

    while (i <= k)
        {
        txBitBlt (txDC(), i*20, 20, 19, 18, Heart, 0, 0);
        i++;
        }
        cin.get ();

    txDeleteDC (Heart);
    }









