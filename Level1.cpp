#include <iostream>
#include <winbgim.h>
int br_color = RED;
int coins[3] = {0, 0, 0};
// X Axis Brick (Size 58,58)
void xbrick(int x1, int x2, int y1, int y2)
{
    rectangle(x1, y1, x2, y2);
    floodfill(x1 + 1, y1 - 1, br_color);
}

// Y Axis Brick (Size 58,58)
void ybrick(int x1, int x2, int y1, int y2)
{
    rectangle(x1, y1, x2, y2);
    floodfill(x2 - 1, y2 + 1, br_color);
}
// Y Axis Brick (Size 58,58)
void y1brick(int x1, int x2, int y1, int y2)
{
    rectangle(x1, y1, x2, y2);
    floodfill(x2 - 1, y2 - 1, br_color);
}
void coin(int x, int y, int color)
{
    setlinestyle(SOLID_LINE, 0xFFFF, 5);
    setcolor(color);
    ellipse(x, y, 0, 360, 15, 40);
    setfillstyle(1, color); // 11
    setlinestyle(SOLID_LINE, 0xFFFF, 0);
}
void enemy(int x, int y, int color)
{
    setcolor(color);
    circle(x + 10, y - 10, 10);
    setfillstyle(11, color);
    floodfill((x + 10) + 1, (y - 10) - 1, color);
    rectangle(x, y, x + 20, y + 58);
    setfillstyle(11, color);
    floodfill(x + 1, (y + 20) - 1, color);
}
void screen1()
{
    int brsize = 58, bry1 = 0, bry2 = 0, brx1 = 0, brx2 = 0;
    // Y Axis Brick
    for (int i = 0; i < 12; i++)
    {
        bry1 += brsize;
        xbrick(0, brsize, bry1, bry2);
        bry1 += 2; // plus 2 for gap
        bry2 += brsize + 2;
    }
    brsize = 58;
    brx2 = 58;
    // X Axis Top Brick
    for (int i = 0; i < 15; i++)
    {
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
        ybrick(brx1, brx2, 58, 0);
    }

    brx1 = 0;
    brsize = 58;
    brx2 = 58;
    // X Axis Bottom Brick
    for (int i = 0; i < 15; i++)
    {
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
        ybrick(brx1, brx2, 720, 660);
    }

    bry1 = 60;
    bry2 = 60;
    // Mid left 10 Brick
    for (int i = 0; i < 10; i++)
    {
        bry1 += brsize;
        xbrick(brsize + 2, (brsize + 2) + brsize, bry1, bry2);
        bry1 += 2; // plus 2 for gap
        bry2 += brsize + 2;
    }

    bry1 = 118;
    bry2 = 60;
    // Center 4x6 Brick
    for (int i = 0; i < 4; i++)
    {
        brx1 = 360;
        brsize = 58;
        brx2 = 360 + 58;
        for (int j = 0; j < 6; j++)
        {

            ybrick(brx1, brx2, bry1, bry2);
            brx1 += brsize;
            brx1 += 2; // plus 2 for gap
            brx2 += brsize + 2;
        }
        bry1 += 60;
        bry2 += 60;
    }
    // Coins
    if (coins[0] == 0)
    {
        coin(400, 618, 1);
    }

    if (coins[1] == 0)
    {
        coin(300, 150, 3);
    }

    if (coins[2] == 0)
    {
        coin(700, 450, 9);
    }
    // Enemy

    enemy(600, 600, GREEN);

    setcolor(br_color);
    setfillstyle(11, br_color); // 11
}
void screen2()
{
    int brsize = 58, bry1 = 0, bry2 = 0, brx1 = 0, brx2 = 0;
    brsize = 58;
    brx2 = 58;
    brx1 = 0;
    // X Axis Top Brick
    for (int i = 0; i < 16; i++)
    {
        ybrick(brx1, brx2, 58, 0);
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
    }

    brx1 = 0;
    brsize = 58;
    brx2 = 58;
    // X Axis Bottom Brick
    for (int i = 0; i < 16; i++)
    {
        ybrick(brx1, brx2, 720, 660);
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
    }

    bry1 = 602;
    bry2 = 660;

    // 2x4 Brick
    for (int i = 0; i < 4; i++)
    {
        brx1 = 180;
        brsize = 58;
        brx2 = 180 + 58;
        for (int j = 0; j < 2; j++)
        {

            y1brick(brx1, brx2, bry1, bry2);
            brx1 += brsize;
            brx1 += 2; // plus 2 for gap
            brx2 += brsize + 2;
        }
        bry1 -= 60;
        bry2 -= 60;
    }

    bry1 = 118;
    bry2 = 60;
    // Center 3x4 Brick
    for (int i = 0; i < 4; i++)
    {
        brx1 = 600;
        brsize = 58;
        brx2 = 600 + 58;
        for (int j = 0; j < 3; j++)
        {

            ybrick(brx1, brx2, bry1, bry2);
            brx1 += brsize;
            brx1 += 2; // plus 2 for gap
            brx2 += brsize + 2;
        }
        bry1 += 60;
        bry2 += 60;
    }

    // Coins
    if (coins[0] == 0)
    {
        coin(240, 380, 1);
    }

    if (coins[1] == 0)
    {
        coin(560, 120, 3);
    }

    if (coins[2] == 0)
    {
        coin(700, 618, 9);
    }
}
void screen3()
{
    int brsize = 58, bry1 = 0, bry2 = 0, brx1 = 0, brx2 = 0;
    brsize = 58;
    brx2 = 58;
    brx1 = 0;
    // X Axis Top Brick
    for (int i = 0; i < 16; i++)
    {
        ybrick(brx1, brx2, 58, 0);
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
    }

    brx1 = 0;
    brsize = 58;
    brx2 = 58;
    // X Axis Bottom Brick
    for (int i = 0; i < 16; i++)
    {
        ybrick(brx1, brx2, 720, 660);
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
    }

    bry1 = 602;
    bry2 = 660;
    // Left L Brick
    for (int i = 0; i < 3; i++)
    {
        int cond = 2;
        brx1 = 120;
        brsize = 58;
        brx2 = brx1 + 58;
        if (i == 2)
        {
            cond = 4;
        }
        for (int j = 0; j < cond; j++)
        {

            y1brick(brx1, brx2, bry1, bry2);
            brx1 += brsize;
            brx1 += 2; // plus 2 for gap
            brx2 += brsize + 2;
        }
        bry1 -= 60;
        bry2 -= 60;
    }

    bry1 = 118;
    bry2 = 60;
    // Center 2x1 Brick
    for (int i = 0; i < 1; i++)
    {
        brx1 = 540;
        brsize = 58;
        brx2 = brx1 + 58;
        for (int j = 0; j < 2; j++)
        {

            ybrick(brx1, brx2, bry1, bry2);
            brx1 += brsize;
            brx1 += 2; // plus 2 for gap
            brx2 += brsize + 2;
        }
        bry1 += 60;
        bry2 += 60;
    }

    brx1 = 480;
    brx2 = brx1 + 58;
    bry1 = 480;
    bry2 = bry1 + 58;
    // Center 4 Brick
    for (int i = 0; i < 4; i++)
    {
        y1brick(brx1, brx2, bry1, bry2);
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
    }

    brx1 = 540;
    brx2 = brx1 + 58;
    bry1 = 540;
    bry2 = bry1 + 58;
    // Below 4 brick
    for (int i = 0; i < 2; i++)
    {
        y1brick(brx1, brx2, bry1, bry2);
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
    }

    // Coins
    if (coins[0] == 0)
    {
        coin(240, 440, 1);
    }

    if (coins[1] == 0)
    {
        coin(600, 440, 3);
    }

    if (coins[2] == 0)
    {
        coin(700, 618, 9);
    }
}
void screen4()
{
    int brsize = 58, bry1 = 0, bry2 = 0, brx1 = 0, brx2 = 0;
    brsize = 58;
    brx2 = 58;
    brx1 = 0;
    // X Axis Top Brick
    for (int i = 0; i < 16; i++)
    {
        ybrick(brx1, brx2, 58, 0);
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
    }

    brx1 = 0;
    brsize = 58;
    brx2 = 58;
    // X Axis Bottom Brick
    for (int i = 0; i < 16; i++)
    {
        ybrick(brx1, brx2, 720, 660);
        brx1 += brsize;
        brx1 += 2; // plus 2 for gap
        brx2 += brsize + 2;
    }

    bry1 = 602;
    bry2 = 660;
    // Left 6x3 Brick
    for (int i = 0; i < 3; i++)
    {
        brx1 = 180;
        brsize = 58;
        brx2 = brx1 + 58;
        for (int j = 0; j < 6; j++)
        {

            y1brick(brx1, brx2, bry1, bry2);
            brx1 += brsize;
            brx1 += 2; // plus 2 for gap
            brx2 += brsize + 2;
        }
        bry1 -= 60;
        bry2 -= 60;
    }

    bry1 = 118;
    bry2 = 60;
    // Center 2x7 Brick
    for (int i = 0; i < 7; i++)
    {
        brx1 = 840;
        brsize = 58;
        brx2 = brx1 + 58;
        for (int j = 0; j < 2; j++)
        {

            ybrick(brx1, brx2, bry1, bry2);
            brx1 += brsize;
            brx1 += 2; // plus 2 for gap
            brx2 += brsize + 2;
        }
        bry1 += 60;
        bry2 += 60;
    }
    outtextxy(900, 580, "Exit");

    // Coins
    if (coins[0] == 0)
    {
        coin(250, 440, 1);
    }

    if (coins[1] == 0)
    {
        coin(500, 440, 3);
    }
    enemy(700, 600, GREEN);
}
