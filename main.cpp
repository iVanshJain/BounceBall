#include <iostream>
#include <conio.h>
#include <winbgim.h>
#include "Level1.cpp"

bool xcollision = false;
bool ycollision = false;
int lifes = 3;
int speed = 10;
int score = 0;
bool enemyhit = false;

void initgraph()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
}
void resetcoins()
{
    for (int i = 0; i < 3; i++)
    {
        coins[i] = 0;
    }
}
void lifeball(int x, int y)
{
    setcolor(WHITE);
    setfillstyle(9, WHITE);
    circle(x, y, 6);
    floodfill(x, y, WHITE);
}
void ball(int x, int y)
{
    setcolor(4);
    setfillstyle(9, 4);
    circle(x, y, 30);
    floodfill(x, y, 4);
}
void drawScreens(int curscreen)
{
    cleardevice();
    if (curscreen == 1)
    {
        screen1();
    }
    else if (curscreen == 2)
    {
        screen2();
    }
    else if (curscreen == 3)
    {
        screen3();
    }
    else if (curscreen == 4)
    {
        screen4();
    }
}

bool ballxCollision(int x, int y)
{

    int left, right;
    right = x + 30;
    left = x - 30;

    // Collision
    if (getpixel(left - 2, y) == 4)
    {
        xcollision = true;
    }
    else if (getpixel(right + 2, y) == 4)
    {
        xcollision = true;
    }

    // Coins Color
    else if (getpixel(left - 2, y) == 1 || getpixel(right + 2, y) == 1)
    {
        coins[0] = 1;
        score += 1;
    }
    else if (getpixel(left - 2, y) == 3 || getpixel(right + 2, y) == 3)
    {
        coins[1] = 1;
        score += 1;
    }
    else if (getpixel(left - 2, y) == 9 || getpixel(right + 2, y) == 9)
    {
        coins[2] = 1;
        score += 1;
    }

    // Enemy
    else if (getpixel(left - 2, y) == GREEN || getpixel(right + 2, y) == GREEN)
    {
        enemyhit = true;
        lifes--;
    }
    else
    {
        xcollision = false;
    }
    return xcollision;
}
bool ballyCollision(int x, int y)
{

    int top, bottom;
    top = y - 30;
    bottom = y + 30;

    if (getpixel(x, bottom + 2) == 4)
    {
        ycollision = true;
    }
    else if (getpixel(x, top - 2) == 4)
    {
        ycollision = true;
    }
    else
    {
        ycollision = false;
    }
    return ycollision;
}
void showLives()
{

    outtextxy(700, 20, "Lives:");
    if (lifes == 1)
    {
        lifeball(785, 30);
    }
    else if (lifes == 2)
    {
        lifeball(785, 30);
        lifeball(800, 30);
    }
    else
    {
        lifeball(785, 30);
        lifeball(800, 30);
        lifeball(815, 30);
    }
}
void showScore()
{
    char strscore[50];
    itoa(score, strscore, 10);
    setcolor(WHITE);
    settextstyle(8, 0, 2);
    outtextxy(850, 20, "Score:");
    outtextxy(930, 20, strscore);
}
void setStyle()
{
    setcolor(br_color);
    setfillstyle(11, br_color);
}

void startScreen()
{

    // Star Screen Window
    rectangle(10, 10, 950, 710);
    setfillstyle(6, 3);
    floodfill(15, 15, 15);

    // Text Material
    settextstyle(1, 0, 7);
    outtextxy(230, 120, "Bounce Ball");
    putpixel(100, 120, YELLOW);

    settextstyle(1, 0, 5);
    setfillstyle(6, 3);
    floodfill(450, 350, 15);
    outtextxy(450, 350, "S-Start");

    floodfill(450, 400, 15);
    outtextxy(450, 400, "Q-Quit");
    floodfill(450, 400, 15);

    // Ball
    circle(180, 380, 120);
    setfillstyle(1, 4);
    floodfill(170, 350, 15);
    // Eyes
    ellipse(150, 350, 0, 360, 15, 35);
    ellipse(210, 350, 0, 360, 15, 35);
    setfillstyle(1, 15);
    floodfill(150, 320, 15);
    setfillstyle(1, 15);
    floodfill(210, 350, 15);

    // Inner eyes
    setcolor(BLACK);
    ellipse(150, 360, 0, 360, 10, 25);
    ellipse(210, 360, 0, 360, 10, 25);
    setfillstyle(1, 0);
    floodfill(150, 365, 0);
    setfillstyle(1, 0);
    floodfill(210, 365, 0);

    // Mouth
    setcolor(WHITE);
    line(130, 420, 230, 420);
    arc(180, 420, 180, 360, 50);

    ellipse(180, 420, 180, 360, 50, 20);
    setfillstyle(1, 15);
    floodfill(180, 425, 15);
}

int main()
{
    initwindow(960, 720);
    char c;
    int curscreen = 1;
    int x = 170, y = 630;
    int page = 1;
    startScreen();
    c = (char)getch();
    if (c == 's')
    {
        cleardevice();
        ball(x, y);
        do
        {
            setStyle();

            // Initial Screen (Level 1)
            if (curscreen == 1)
            {
                screen1();
            }

            // Score and Lives Counter Show
            showScore();
            showLives();

            setStyle();

            // Double Buffering Setup
            setactivepage(page);
            setvisualpage(1 - page);

            // Enemy Hit Logic
            if (enemyhit)
            {
                drawScreens(curscreen);
                x = 170;
                y = 630;
                enemyhit = false;
                resetcoins();
                score = 0;
                curscreen = 1;
            }

            if (lifes == 0)
            {
                c = 'q';
                cleardevice();
                break;
            }

            // Exit Game
            if (curscreen == 4 && x > getmaxx() - 60)
            {
                c = 'q';
                cleardevice();
                break;
            }

            c = (char)getch();

            drawScreens(curscreen);
            switch (c)
            {
            case KEY_UP:
                y -= 10;
                if (ballyCollision(x, y) == false)
                {
                    ball(x, y);
                    page = 1 - page;
                }
                else
                {
                    y += 10;
                }

                break;
            case KEY_DOWN:
                y += 10;
                if (ballyCollision(x, y) == false)
                {
                    ball(x, y);
                    page = 1 - page;
                }
                else
                {
                    y -= 10;
                }
                break;

            case KEY_LEFT:
                x -= 10;
                if (ballxCollision(x, y) == false)
                {
                    ball(x, y);
                    page = 1 - page;
                }
                else
                {
                    x += 10;
                }
                break;
            case KEY_RIGHT:
                if (x > getmaxx() - 60)
                {
                    curscreen++;
                    drawScreens(curscreen);
                    x = 50;
                    resetcoins();
                }
                x += 10;
                if (ballxCollision(x, y) == false)
                {
                    ball(x, y);
                    page = 1 - page;
                }
                else
                {
                    x -= 10;
                }
                break;
            }

        } while (c != 'q' && c != 'Q');
    }
    getch();
    closegraph();
    return 0;
}
