#include "TXLib.h"
using namespace std;

struct CBall
    {
    int x, y, vx, vy, radius;       //доработать до полноценной игры

    };

void Control ();
void Physics (int dt);
void DrawBalls (CBall balls [], int nNumberOfBalls);
void Instruction ();
void SphereMovement ();
void Heart (int hearts);

double Length (CBall ball1, CBall ball2);
int Collision (CBall* ball1, CBall* ball2);
                                                                             //d*d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)
                                                        //d = sqrt ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
const int Lengthwindow = 800;
      int Widthwindow  = 600;                           //21 - а, 22 - ы, 23 - ы, 24 - ы, 25 - в, 26 - в, 27 - в, 28 - в, 29 - в, 30 - в


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
    Instruction ();
    SphereMovement ();
    return 0;
    }

//=============================================================================//

void Instruction ()
     {
     cout << "Добро пожаловать в игру" <<endl;
     txSleep (1000);
     cout << "Правила игры:" <<endl;
     cout << "Надо избегать столкновения твоего (самого маленького шарика) со следующим, по размеру" <<endl;
     cout << "Нажимая стрелочки, можно смещать свой шарик" <<endl;
     cout << "У тебя 5 попыток" <<endl;
     txSleep (1000);
     }

//=============================================================================//

void SphereMovement ()
    {
    int hearts = 5;
    Heart (hearts);
    txSleep (1000);
    //cin.get ();

    CBall balls [4] = {{100, 100, 5, 5, 20},
                       {200, 200, 8, 8, 30},
                       {300, 300, 10, 10, 40},
                       {400, 400, 12, 12, 50}};

    //int radius = 20;
    int dt = 1;
    //cout <<"значение ячейки в " << __func__ << " == " << x;
    //cin.get ();
    while (!GetAsyncKeyState (VK_ESCAPE))       //сделать 3 и 4 шарик
        {
        //vx = 10;                                              исходник TXLib.h смотреть в сообщении
        txSetFillColor (TX_BLACK);
        txClear ();

        int i = 0;
        while (i < 4)
            {
            balls [i].Draw ();
            i++;
            }

        //cout <<"DrawKotik до вызова функции MovementKotik x="<< x << " y=" << y <<" r="<< radius << endl;
        //cin.get ();

        Physics ();


        if (Length (balls [0], balls [1]) <= balls [0].radius + balls [0].radius)
            {
            txMessageBox ("ой ой ой", "окружности пересекаются", MB_ICONERROR);
            txSetFillColor (TX_GREEN);
            txClear ();
            hearts--;
            if (hearts == 0)
                {
                txMessageBox ("хах, сегодня не твой день", "все заново", MB_ICONERROR);
                break;
                }
            Heart (hearts);

            txSleep (1000);

            }

        Control (balls [0].x , balls [0].y);

        //Length (ball1.x, 1ball1.y, ball2.x, ball2.y);

        //cout << Length (ball1, ball2) << endl;     подумать над тем, какие пары шариков нужно пассматривать, а какие нельзя

        i = 0;
        while (i < 4)
            {
            int j = i + 1;
            while (j < 4)
                {
                Collision (&balls [i], &balls [j]);
                cout << i << "  "<< j << endl;
                j++;

                }

            i++;
            }
        /*Collision (&balls [0], &balls [1]);

        Collision (&balls [0], &balls [2]);
        Collision (&balls [0], &balls [3]);


        Collision (&balls [1], &balls [2]);
        Collision (&balls [1], &balls [3]);
        Collision (&balls [2], &balls [3]); */
        //cout <<"DrawKotik после вызова функции MovementKotik x="<< x << " y=" << y <<" r="<< radius << endl;
        //cin.get ();

        txSleep (10);
        }
     }

//=============================================================================// сделать счет, проигрыши и выигрыши

void DrawBalls (CBall balls [], int nNumberOfBalls) const
    {
    for (int i = 0; i < nNumberOfBalls ; i++)
        {                                       // неявный параметр указывающий на текущий объект, при вызове указывается не в скобках, а слева от имени ф-и через стрелку или точку
        //cout <<"значение ячейки в S"<< &x;       //   |
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

void Control (int x, int y)
    {
    if (GetAsyncKeyState (VK_RIGHT))  this->x = this->x + 10;
    if (GetAsyncKeyState (VK_LEFT))   this->x = this->x - 10;
    if (GetAsyncKeyState (VK_UP))     this->y = this->y - 10;
    if (GetAsyncKeyState (VK_DOWN))   this->y = this->y + 10;
    //if (GetAsyncKeyState (VK_RETURN)) this->vx = 0, this->vy = 0;

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

void Heart (int hearts)
    {
    HDC Heart = txLoadImage("Heart.bmp");
    int i = 1;

    while (i <= hearts)
        {
        txBitBlt (txDC(), i*20, 20, 19, 18, Heart, 0, 0);
        i++;
        }
        //cin.get ();

    txDeleteDC (Heart);
    }








