#include<iostream>
#include<fstream>
#include "youregraphics.h"
using  namespace std;
void strikup(int& i, int& j, int& x, int& y)
{
    if (i > x)
    {
        x = i++;
        y = j++;
    }
    else if (i < x)
    {
        x = i--;
        y = j++;
    }
    else {
        
            y = j++;
    }
}
void left(int& i, int& j, int& x, int& y)
{
    if (j > y)
    {
        x = i++;
        y = j++;
    }
    if (j < y)
    {
        x = i++;
        y = j--;
    }
}
void rigt(int& i, int& j, int& x, int& y)
{
    if (j > y)
    {
        x = i--;
        y = j++;
    }
    if (j < y)
    {
        x = i--;
        y = j--;
    }
}
void down(int& i, int& j, int& x, int& y)
{
    if (i > x)
    {
        x = i++;
        y = j--;
    }
    if (i < x)
    {
        x = i--;
        y = j--;
    }
}

//  h = GetSystemMetrics(SM_CYSCREEN); 720
// w = GetSystemMetrics(SM_CXSCREEN); 1280
// cout << h << endl << w;

int main() {
    int lives;
    int x_axis[10] = { 0 };//to store the coordinates of bricks
    int b[5][10];//for health of boxes
    int c1 = 255, c2 = 0, c3 = 0;//for colors of bricks
    int m, n, i, j ,u1, u2, u3, u4, u5;//m and n for coordinates of pad and i and j are coordinates of ellipse
    int score;
    int count = 1;
    int x1 = 0, y1 = 0, x = 0, y = 0;//x1 and y1 are coordinates of line and   x and y are coordinates of ellipse
    int h = 0, w = 0;
    getWindowDimensions(w, h); // w = 880, h = 480
    //ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    bool flag = false;
    bool symbol = true;
    cls();
    w /= 2; // w = 440
    x1 = w - 170; // x1 = 270
    w += 170; // w = 610
  
    showConsoleCursor(false);
    char c;
    int start;
    cout << "Press accordingly: \n";
    cout << "1: Start Game: \n";
    cout << "2: Load Game: \n";
    cin >> start;
    drawLine(x1 - 4, 18, w + 2, 18, 205, 205, 0);
    drawLine(x1 - 2, y1 + 20, x1 - 2, h, 205, 205, 0);
    drawLine(w + 2, y1 + 20, w + 2, h, 205, 205, 0);
    if (start == 2) {
        gotoxy(0, 0);
        ifstream load_file("saved_game.txt");
        if (!load_file)
            cout << "You haven't saved any game yet";
        else
        {
            load_file >> m;
            load_file >> n;
            load_file >> i;
            load_file >> j;
            load_file >> count;
            load_file >> lives;
            load_file >> score;
            for (int q = 0, z = 1; z < 6 && q < 5; q++, z++) {
                for (int w = 0; w < 10; w++) {
                    load_file >> b[q][w];
                    if (b[q][w])
                        drawRectangle(x1 + (w * 34), 20 * z, x1 + (w * 34) + 34, (20 * z) + 20, 0, 0, 0, c1, c2, c3);
                }
                c2 += 51;
                c3 += 51;
            }
            load_file.close();
        }
    }
    if (start == 1) {
        lives = 3;
        score = 0;
        x = 0, y = 0;
        i = x1+50, j = h - 250, count = 1; //i and j are coordinates of ellipse
        m = 0, n = h - 50;
        //pad
        //m and n for coordinates of pad
        int row = 0, column = 0;
        gotoxy(0, 0);
        for (int r = 20; r < 120; r += 20)
        {
            column = 0;
            for (int col = x1; col <= w - 34; col += 34)
            {
                drawRectangle(col, r, col + 34, 20 + r, 0, 0, 0, c1, c2, c3);
                if (row == 0)b[row][column] = 3;
                else if (row == 1)b[row][column] = 1;
                else b[row][column] = 1;
                column++;
            }
            row++;
            c2 += 51;
            c3 += 51;
        }
    } 
    //original height is same
    // value of width is changed
    for (int t = 0, p = x1; t < 10; t++, p += 34) //To store the coordinates of Boxes
        x_axis[t] = p;
    while (true)
    {
      
        //x1 and y1 intial coordinates of pad
        // h and w maximum coordinates of pad
        //pad
        //m and n for coordinates of pad
        c = getKey();
        drawRectangle(m, n, m + 60, n + 15, 0, 0, 0, 255, 255, 0);
        delay(1);
        drawRectangle(m, n, m + 60, n + 15, 0, 0, 0, 0, 0, 0);
        if (c == 'q') break;
        if (c == 'p') {
            while (true) {
                c = getKey();
                if (c == 'c') break;
            }
        }
        if (c == 's') {
            ofstream save_file("saved_game.txt");
            save_file << m << endl;
            save_file << n << endl;
            save_file << i << endl;
            save_file << j << endl;
            save_file << count << endl;
            save_file << lives << endl;
            save_file << score << endl;
            for (int q = 0; q < 5; q++)
                for (int w = 0; w < 10; w++)
                    save_file << b[q][w] << endl;
            save_file.close();
        }
        if (c == 'w') m = x1;
        if (c == KEY_RIGHT) m += 10;
        if (c == KEY_LEFT) m -= 10;
        //if (c == 's')m = w - 60;
        if (m < x1)
            m = x1;
        if ((m + 60) >= w)
            m = w - 60;
        //ellipse
        drawEllipse(i, j, i + 13, j + 13, 100, 255, 200, 0, 255, 0);
        delay(1);
        drawEllipse(i, j, i + 13, j + 13, 0, 0, 0, 0, 0, 0);
        if (count == 1)
        {
            count++;
            x = i++;
            y = j++;
        }
        if (j + 13 == 100 || j + 13 == 80 || j + 13 == 60 || j + 13 == 40)
        {
            if (j + 13 == 100)
            {
                for (int h = 0; h < 10; h++)
                {
                    if ((i + 13) >= x_axis[h] && i <= (x_axis[h] + 34) && b[4][h] == 1)
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 100, x_axis[h] + 34, 120, 0, 0, 0, 0, 0, 0);
                        strikup(i, j, x, y);
                        b[4][h]--;
                        flag = true;
                    }
                }
            }
            if (j + 13 == 80)
            {
                for (int h = 0; h < 10; h++)
                {
                    if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[3][h] == 1)//
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 80, x_axis[h] + 34, 100, 0, 0, 0, 0, 0, 0);//
                        strikup(i, j, x, y);
                        b[3][h] = 0;
                        flag = true;
                    }
                }
            }
            if (j + 13 == 60)
            {
                for (int h = 0; h < 10; h++)
                {
                    if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[2][h] == 1)
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 60, x_axis[h] + 34, 80, 0, 0, 0, 0, 0, 0);//
                        strikup(i, j, x, y);
                        b[2][h] = 0;
                        flag = true;
                    }
                }
            }
             if (j + 13 == 40)
             {
                 for (int h = 0; h < 10; h++)
                 {
                     if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[1][h] == 1)//
                     {
                         score += 100;
                         drawRectangle(x_axis[h], 40, x_axis[h] + 34, 60, 0, 0, 0, 0, 0, 0);//
                         strikup(i, j, x, y);
                         b[1][h] = 0;//
                         flag = true;
                     }
                 }

             }
                
         
        }
        if (j + 13 == 100 || j + 13 == 80 || j + 13 == 60 || j + 13 == 40)
        {
            if (j + 13 == 100)
            {
                for (int h = 0; h < 10; h++)
                {
                    if ((i + 13) >= x_axis[h] && i <= (x_axis[h] + 34) && b[4][h] == 1)
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 100, x_axis[h] + 34, 120, 0, 0, 0, 0, 0, 0);
                        down(i, j, x, y);
                        b[4][h]--;
                        flag = true;
                    }
                }
            }
            if (j + 13 == 80)
            {
                for (int h = 0; h < 10; h++)
                {
                    if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[3][h] == 1)//
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 80, x_axis[h] + 34, 100, 0, 0, 0, 0, 0, 0);//
                        down(i, j, x, y);
                        b[3][h] = 0;
                        flag = true;
                    }
                }
            }
            if (j + 13 == 60)
            {
                for (int h = 0; h < 10; h++)
                {
                    if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[2][h] == 1)
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 60, x_axis[h] + 34, 80, 0, 0, 0, 0, 0, 0);//
                        down(i, j, x, y);
                        b[2][h] = 0;
                        flag = true;
                    }
                }
            }
            if (j + 13 == 40)
            {
                for (int h = 0; h < 10; h++)
                {
                    if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[1][h] == 1)//
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 40, x_axis[h] + 34, 60, 0, 0, 0, 0, 0, 0);//
                        down(i, j, x, y);
                        b[1][h] = 0;//
                        flag = true;
                    }
                }

            }


        }
        if (j == 100 || j == 80 || j == 60 || j == 40 || j == 20 || j == 120)
        {
            if (j == 120)
            {
                for (int h = 0; h < 10; h++)
                {
                    if ((i + 13) >= x_axis[h] && i <= (x_axis[h] + 34) && b[4][h] == 1)
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 100, x_axis[h] + 34, 120, 0, 0, 0, 0, 0, 0);
                        strikup(i, j, x, y);
                        b[4][h]--;
                        flag = true;
                    }
                }
            }
            else if (j == 100)
            {
                for (int h = 0; h < 10; h++)
                {
                    if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[3][h] == 1)//
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 80, x_axis[h] + 34, 100, 0, 0, 0, 0, 0, 0);//
                        strikup(i, j, x, y);
                        b[3][h] = 0;
                        flag = true;
                    }
                }
            }
            else if (j == 80)
            {
                for (int h = 0; h < 10; h++)
                {
                    if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[2][h] == 1)
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 60, x_axis[h] + 34, 80, 0, 0, 0, 0, 0, 0);//
                        strikup(i, j, x, y);
                        b[2][h] = 0;
                        flag = true;
                    }
                }
            }
            else if (j == 60)//
            {
                for (int h = 0; h < 10; h++)
                {
                    if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[1][h] == 1)//
                    {
                        score += 100;
                        drawRectangle(x_axis[h], 40, x_axis[h] + 34, 60, 0, 0, 0, 0, 0, 0);//
                        strikup(i, j, x, y);
                        b[1][h] = 0;//
                        flag = true;
                    }
                }
            }
            else if (j == 40)//
            {
                for (int h = 0; h < 10; h++)
                {
                    if (((i + 13) >= x_axis[h]) && (i <= (x_axis[h] + 34)) && b[0][h] >= 1)//
                    {
                       
                        if(b[0][h]==3)
                        drawRectangle(x_axis[h], 20, x_axis[h] + 34, 40, 0, 0, 0, 255, 255, 255);//
                        if (b[0][h] == 2)
                            drawRectangle(x_axis[h], 20, x_axis[h] + 34, 40, 0, 0, 0, 233, 233, 233);//
                        if (b[0][h] == 1)
                        {
                            score += 100;
                            drawRectangle(x_axis[h], 20, x_axis[h] + 34, 40, 0, 0, 0, 0, 0, 0);//
                        }
                            strikup(i, j, x, y);
                        b[0][h] --;//
                        flag = true;
                    }
                }
            }
            else if (j == 20)//
            {
                strikup(i, j, x, y);
            }
            if (!flag)
            {
                if (j < y)
                {
                    if (i > x)
                    {
                       x=i++;
                       y = j--;
                    }
                    else if (i < x)
                    {
                        x = i--;
                        y = j--;
                    }
                    else
                    {
                        y = j--;
                    }
                }
                else
                {
                    strikup(i, j, x, y);
                }
            }
        }

        else if (j == (h - 65))
        {
            if (((i + 13) >= m) && (i <= (m + 60)))////important change
            {
                if (i >= (m + 20) && i + 13 <= m + 40)
                {
                    x = i;
                    y = j--;

                }
                else {
                    if (i <= (m + 20))
                    {
                        x = i--;
                        y = j--;
                    }
                    else
                    {
                        x = i++;
                        y = j--;
                    }
                }
  /*              else
                {
                    if (i >= x)
                    {
                        x = i++;
                        y = j--;
                    }
                    if (i <= x)
                    {
                        x = i--;
                        y = j--;
                    }
                }*/
            }
            else
            {  
                lives--;
                if (lives == 0)
                {
                    cls();
                    gotoxy(20, 20);
                    cout << "Game Over ";
                    break;
                }
                else {
                    
                    down(i, j, x, y);
                }
            }
        }
        else if (i == x1)
        {
            left(i, j, x, y);
        }
        else if (i == (w - 16))
        {
            rigt(i, j, x, y);
        }
        else if (i > x && j < y)
        {
            x = i++;
            y = j--;
        }
        else if (i < x && j < y)
        {
            x = i--;
            y = j--;
        }
        else if (i < x && j > y)
        {
            x = i--;
            y = j++;
        }
        else if (i == x && j > y)
        {
            x = i;
            y = j++;
        }
        else if (i == x && j < y)
        {
            x = i;
            y = j--;
        }
        else
        {
            x = i++;
            y = j++;
        }
        if (i == x1)
        {
            left(i, j, x, y);
        }
        if (i + 16 == w)//
        {
            rigt(i, j, x, y);

        }
       
        //if (j == (h - 70))
        //{
        //    if (((i + 16) >= m) && (i <= (m + 60)))////important change
        //    {
        //        down(i, j, x, y);
        //    }
        //}
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (b[i][j] != 0)
                    symbol = false;
            }
        }
        if (symbol)
        {
            cls();
            gotoxy(50, 30);
            cout << "Congratulations\nYou Won";
            break;
        }
        gotoxy(70, 0);
        cout << "Score: "<<score;
        gotoxy(40, 0);
        cout << "Player Lives: " << lives;
        flag = false; 
    }

    ifstream highscore1("high_scores.txt");
    if (highscore1)
    while (highscore1 >> u1 >> u2 >> u3 >> u4 >> u5) {
        if (score >= u1) {
            ofstream highscore("high_scores.txt");
            highscore << score << endl;
            highscore << u1 << endl;
            highscore << u2 << endl;
            highscore << u3 << endl;
            highscore << u4 << endl;
            gotoxy(0, 0);
            cout << "HIGH SCORES: \n";
            cout << score << endl;
            cout << u1 << endl;
            cout << u2 << endl;
            cout << u3 << endl;
            cout << u4 << endl;
            highscore.close();
        }
        else if (score >= u2) {
            ofstream highscore("high_scores.txt");
            highscore << u1 << endl;
            highscore << score << endl;
            highscore << u2 << endl;
            highscore << u3 << endl;
            highscore << u4 << endl;
            gotoxy(0, 0);
            cout << "HIGH SCORES: \n";
            cout << u1 << endl;
            cout << score << endl;
            cout << u2 << endl;
            cout << u3 << endl;
            cout << u4 << endl;
            highscore.close();
        }
        else if (score >= u3) {
            ofstream highscore("high_scores.txt");
            highscore << u1 << endl;
            highscore << u2 << endl;
            highscore << score << endl;
            highscore << u3 << endl;
            highscore << u4 << endl;
            gotoxy(0, 0);
            cout << "HIGH SCORES: \n";
            cout << u1 << endl;
            cout << u2 << endl;
            cout << score << endl;
            cout << u3 << endl;
            cout << u4 << endl;
            highscore.close();
        }
        else if (score >= u4) {
            ofstream highscore("high_scores.txt");
            highscore << u1 << endl;
            highscore << u2 << endl;
            highscore << u3 << endl;
            highscore << score << endl;
            highscore << u4 << endl;
            gotoxy(0, 0);
            cout << "HIGH SCORES: \n";
            cout << u1 << endl;
            cout << u2 << endl;
            cout << u3 << endl;
            cout << score << endl;
            cout << u4 << endl;
            highscore.close();
        }
        else if (score >= u5) {
            ofstream highscore("high_scores.txt");
            highscore << u1 << endl;
            highscore << u2 << endl;
            highscore << u3 << endl;
            highscore << u4 << endl;
            highscore << score << endl;
            gotoxy(0, 0);
            cout << "HIGH SCORES: \n";
            cout << u1 << endl;
            cout << u2 << endl;
            cout << u3 << endl;
            cout << u4 << endl;
            cout << score << endl;
            highscore.close();
        }
        else {
            highscore1.close();
            break;
        }
    }
    else {
        ofstream highscore("high_scores.txt");
        highscore << 0 << endl;
        highscore << 0 << endl;
        highscore << 0 << endl;
        highscore << 0 << endl;
        highscore << 0 << endl;

        ifstream highscore1("high_scores.txt");
        while (highscore1 >> u1 >> u2 >> u3 >> u4 >> u5) {
            if (score >= u1) {
                ofstream highscore("high_scores.txt");
                highscore << score << endl;
                highscore << u1 << endl;
                highscore << u2 << endl;
                highscore << u3 << endl;
                highscore << u4 << endl;
                gotoxy(0, 0);
                cout << "HIGH SCORES: \n";
                cout << score << endl;
                cout << u1 << endl;
                cout << u2 << endl;
                cout << u3 << endl;
                cout << u4 << endl;
                highscore.close();
            }
            else if (score >= u2) {
                ofstream highscore("high_scores.txt");
                highscore << u1 << endl;
                highscore << score << endl;
                highscore << u2 << endl;
                highscore << u3 << endl;
                highscore << u4 << endl;
                gotoxy(0, 0);
                cout << "HIGH SCORES: \n";
                cout << u1 << endl;
                cout << score << endl;
                cout << u2 << endl;
                cout << u3 << endl;
                cout << u4 << endl;
                highscore.close();
            }
            else if (score >= u3) {
                ofstream highscore("high_scores.txt");
                highscore << u1 << endl;
                highscore << u2 << endl;
                highscore << score << endl;
                highscore << u3 << endl;
                highscore << u4 << endl;
                gotoxy(0, 0);
                cout << "HIGH SCORES: \n";
                cout << u1 << endl;
                cout << u2 << endl;
                cout << score << endl;
                cout << u3 << endl;
                cout << u4 << endl;
                highscore.close();
            }
            else if (score >= u4) {
                ofstream highscore("high_scores.txt");
                highscore << u1 << endl;
                highscore << u2 << endl;
                highscore << u3 << endl;
                highscore << score << endl;
                highscore << u4 << endl;
                gotoxy(0, 0);
                cout << "HIGH SCORES: \n";
                cout << u1 << endl;
                cout << u2 << endl;
                cout << u3 << endl;
                cout << score << endl;
                cout << u4 << endl;
                highscore.close();
            }
            else if (score >= u5) {
                ofstream highscore("high_scores.txt");
                highscore << u1 << endl;
                highscore << u2 << endl;
                highscore << u3 << endl;
                highscore << u4 << endl;
                highscore << score << endl;
                gotoxy(0, 0);
                cout << "HIGH SCORES: \n";
                cout << u1 << endl;
                cout << u2 << endl;
                cout << u3 << endl;
                cout << u4 << endl;
                cout << score << endl;
                highscore.close();
            }
            highscore1.close();
        }
    }
    showConsoleCursor(true);

    return 0;
}