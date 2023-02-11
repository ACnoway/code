//上下左右键控制
#include <bits/stdc++.h>
#include <windows.h>
int a[24][17], i, j, tim = 800, ti = 800, shape = 0, b, bn, ta[4][4], turn[4][4], nex[4][4], nextshape, add = 0, score = 0, speed = 1, ok = 1, mouse = 0, best = 0;
void Place(const int x, const int y)
{
   COORD PlaceCursorHere;
   PlaceCursorHere.X = y;
   PlaceCursorHere.Y = x;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), PlaceCursorHere);
   return;
}
void color(int x)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void appear()
{
   for (i = 3; i <= 22; i++)
      for (j = 1; j <= 15; j++)
         if (a[i][j] != 0)
         {
            Place(i - 2, 2 * j);
            printf("■");
         }
}
void disappear()
{
   for (i = 3; i <= 22; i++)
      for (j = 1; j <= 15; j++)
         if (a[i][j] == 2)
         {
            Place(i - 2, 2 * j);
            printf(" ");
         }
}
int search(int x0, int y0, int x, int y)
{
   POINT pt;
   HWND h = GetForegroundWindow();
   GetCursorPos(&pt);
   ScreenToClient(h, &pt);
   if (pt.x >= x0 && pt.y >= y0 && pt.x <= x && pt.y <= y)
   {
      if (mouse != 0)
      {
         Sleep(100);
         return 2;
      }
      else
         return 1;
   }
   else
      return 0;
}
void button(int x)
{
   int m = x * 10;
   if (x < 3)
   {
      Place(22, m);
      printf("┌┄┄┄┐");
      Place(23, m);
      {
         if (x == 0)
         {
            if (ok != 0)
               printf("┆开始 ┆");
            else
               printf("┆暂停 ┆");
         }
         if (x == 1)
            printf("┆重置 ┆");
         if (x == 2)
            printf("┆退出 ┆");
      }
      Place(24, m);
      printf("└┄┄┄┘");
   }
   else
   {
      Place(9, m - 33);
      printf("┌┄┄┐");
      Place(10, m - 33);
      {
         if (x == 4)
            printf("┆是┆");
         else
            printf("┆否┆");
      }
      Place(11, m - 33);
      printf("└┄┄┘");
   }
}
void menu(int x)
{
   int k, l;
   if (x == 0)
   {
      if (ok != 0)
      {
         ok = 0;
         return;
      }
      else
         while (1)
         {
            mouse = GetAsyncKeyState(VK_LBUTTON);
            Place(9, 13);
            printf("暂停");
            if (search(7, 360, 71, 390) == 2)
               break;
            Sleep(50);
         }
      Place(9, 12);
      for (j = 1; j <= 6; j++)
         printf(" "); // appear();
   }
   else
   {
      for (i = 1; i <= 20; i++)
         for (j = 2; j <= 30; j++)
         {
            Place(i, j);
            printf(" ");
         }
      Place(7, 2);
      for (i = 1; i <= 15; i++)
         printf("┄");
      Place(12, 2);
      for (i = 1; i <= 15; i++)
         printf("┄");
      Place(8, 6);
      printf("你想要 ");
      if (x == 1)
         printf("重置?");
      if (x == 2)
         printf("exit?");
      button(4);
      button(5);
      while (1)
      {
         mouse = GetAsyncKeyState(VK_LBUTTON);
         for (i = 0; i <= 1; i++)
         {
            k = search(63 + i * 80, 150, 110 + i * 80, 180);
            if (k != 2)
            {
               if (k == 1)
                  color(15);
               else
                  color(7);
               button(i + 4);
            }
            else
            {
               for (l = 7; l <= 12; l++)
                  for (j = 2; j <= 30; j++)
                  {
                     Place(l, j);
                     printf(" ");
                  }
               if (i == 0)
               {
                  if (x == 1)
                     ok = 2;
                  else
                     exit(0);
               }
               return;
            }
         }
         Sleep(50);
      }
   }
}
void click()
{
   for (i = 0; i <= 2; i++)
   {
      mouse = GetAsyncKeyState(VK_LBUTTON);
      int k = search(i * 80 + 7, 360, i * 80 + 71, 390);
      if (k != 2)
      {
         if (k == 1)
            color(15);
         else
            color(7);
         button(i);
         color(7);
      }
      else
      {
         menu(i);
         return;
      }
   }
   Sleep(50);
}
void ss()
{
   Place(9, 39);
   printf("%d", score);
   if (score >= speed * 100)
   {
      speed++;
      ti = ti - 200;
      if (ti < 0)
         ti = 0;
      else
      {
         for (i = 1; i <= 4; i++)
         {
            Place(9, 12);
            printf("加速!");
            Sleep(70);
            Place(9, 12);
            for (j = 1; j <= 9; j++)
               printf(" ");
            Sleep(70);
         }
         Sleep(200);
      }
   }
   if (best < score)
      best = score;
   appear();
   Place(12, 39);
   printf("%d", speed);
   Place(15, 39);
   printf("%d", best);
}
void replace()
{
   for (i = 1; i <= 20; i++)
      for (j = 2; j <= 30; j++)
      {
         Place(i, j);
         printf(" ");
      }
   for (i = 0; i <= 22; i++)
      for (j = 1; j <= 15; j++)
         a[i][j] = 0;
   for (i = 1; i <= 15; i++)
      a[23][i] = 1;
   for (i = 1; i <= 23; i++)
   {
      a[i][0] = 1;
      a[i][16] = 1;
   }
   ss();
   tim = 800;
   ti = 800;
   shape = 0;
   add = 0;
   score = 0;
   speed = 1;
}
void change(int x)
{
   int q = 0, l;
   for (l = 1; l <= x; l++)
   {
      for (j = 0; j <= 2 + add; j++)
      {
         for (i = 2 + add; i >= 0; i--)
         {
            turn[j][q] = ta[i][j];
            q++;
            if (q > 2 + add)
               q = 0;
         }
      }
      for (i = 0; i <= 3; i++)
         for (j = 0; j <= 3; j++)
            ta[i][j] = turn[i][j];
   }
}
void born()
{
   int x, q = 0;
   srand(time(NULL));
   bn = b;
   shape = nextshape;
   x = rand() % 12 + 1;
   if (b == 5 && x > 1)
   {
      x--;
      add = 1;
   }
   for (i = 0; i <= 2 + add; i++)
      for (j = x; j <= x + 2 + add; j++)
      {
         a[i][j] = nex[i][q];
         q++;
         if (q > 2 + add)
            q = 0;
      }
   add = 0;
}
void next()
{
   srand(time(NULL));
   b = rand() % 7;
   nextshape = rand() % 4;
   add = 0;
   for (i = 3; i <= 6; i++)
      for (j = 37; j <= 45; j++)
      {
         Place(i, j);
         printf(" ");
      }
   for (i = 0; i <= 3; i++)
      for (j = 0; j <= 3; j++)
         nex[i][j] = turn[i][j] = ta[i][j] = 0;
   ta[1][1] = 2;
   if (b == 0)
      ta[1][2] = ta[1][0] = ta[0][1] = 2;
   if (b == 1)
      ta[1][2] = ta[1][0] = ta[0][0] = 2;
   if (b == 2)
      ta[1][2] = ta[1][0] = ta[0][2] = 2;
   if (b == 3)
      ta[1][0] = ta[0][1] = ta[0][2] = 2;
   if (b == 4)
      ta[0][0] = ta[0][1] = ta[1][2] = 2;
   if (b == 5)
   {
      ta[1][0] = ta[1][2] = ta[1][3] = 2;
      add = 1;
   }
   if (b == 6)
      ta[0][0] = ta[0][1] = ta[1][0] = 2;
   if (nextshape > 0 && b != 6)
   {
      change(nextshape);
      for (i = 0; i <= 3; i++)
         for (j = 0; j <= 3; j++)
         {
            nex[i][j] = turn[i][j];
            if (nex[i][j] == 2)
            {
               Place(i + 3, j * 2 + 37);
               printf("■");
            }
         }
   }
   else
   {
      for (i = 0; i <= 3; i++)
         for (j = 0; j <= 3; j++)
         {
            nex[i][j] = ta[i][j];
            if (nex[i][j] == 2)
            {
               Place(i + 3, j * 2 + 37);
               printf("■");
            }
         }
   }
}
void clear()
{
   int c = 0, f = 0, l[23], s = 0, k;
   for (i = 3; i <= 22; i++)
   {
      l[i] = 0;
      for (j = 1; j <= 15; j++)
         c = a[i][j] + c;
      if (c == 15)
      {
         for (j = 1; j <= 15; j++)
            a[i][j] = 0;
         for (k = i - 1; k >= 2; k--)
            for (j = 1; j <= 15; j++)
               a[k + 1][j] = a[k][j];
         f++;
         l[i] = 1;
         s = 5;
      }
      c = 0;
   }
   score = score + f * 10;
   while (f > 1)
   {
      score = score + f * 5;
      f--;
   }
   f = 0;
   while (s > 0)
   {
      for (i = 22; i >= 3; i--)
         if (l[i] == 1)
         {
            Place(i - 2, 2);
            for (j = 1; j <= 15; j++)
               printf("■");
         }
      Sleep(70);
      for (i = 22; i >= 3; i--)
         if (l[i] == 1)
         {
            Place(i - 2, 2);
            for (j = 1; j <= 30; j++)
               printf(" ");
         }
      Sleep(70);
      s--;
   }
   for (i = 3; i <= 22; i++)
      for (j = 1; j <= 15; j++)
      {
         Place(i - 2, 2 * j);
         printf(" ");
      }
   appear();
}
void control()
{
   int up, down, right, left, c = 0, d = 0, x, y, no = 0, k, l = 0, q = 0;
   k = shape;
   add = 0;
   up = GetAsyncKeyState(VK_UP);
   down = GetAsyncKeyState(VK_DOWN);
   right = GetAsyncKeyState(VK_RIGHT);
   left = GetAsyncKeyState(VK_LEFT);
   if (down != 0)
   {
      tim = 0;
   }
   if (left != 0 || right != 0)
   {
      Sleep(100);
      disappear();
      for (i = 0; i <= 22; i++)
         for (j = 1; j <= 15; j++)
         {
            if (a[i][j] == 2 && a[i][j - 1] != 1)
               c++;
            if (a[i][j] == 2 && a[i][j + 1] != 1)
               d++;
         }
      for (i = 0; i <= 22; i++)
         for (j = 1; j <= 15; j++)
            if (left != 0 && c == 4 && a[i][j] == 2)
            {
               a[i][j - 1] = a[i][j];
               a[i][j] = 0;
            }
      for (i = 0; i <= 22; i++)
         for (j = 15; j >= 1; j--)
            if (right != 0 && d == 4 && a[i][j] == 2)
            {
               a[i][j + 1] = a[i][j];
               a[i][j] = 0;
            }
      appear();
   }
   if (up != 0 && bn != 6)
   {
      Sleep(150);
      disappear();
      for (i = 0; i <= 22; i++)
      {
         for (j = 1; j <= 15; j++)
            if (a[i][j] == 2)
            {
               x = i;
               no = 1;
               break;
            }
         if (no == 1)
            break;
      }
      no = 0;
      for (j = 1; j <= 15; j++)
      {
         for (i = 0; i <= 22; i++)
            if (a[i][j] == 2)
            {
               y = j;
               no = 1;
               break;
            }
         if (no == 1)
            break;
      }
      no = 0;
      if (k == 1)
         y--;
      if (k == 2)
         x--;
      add = 0;
      if (bn == 5)
      {
         add = 1;
         if (k == 0 || k == 2)
            x--;
         if (k == 1 || k == 3)
            y--;
      }
      for (i = 0; i <= 3; i++)
         for (j = 0; j <= 3; j++)
            ta[i][j] = a[x + i][y + j];
      if (bn >= 0 && bn < 5)
      {
         if (k == 0)
            ta[2][0] = 0;
         if (k == 1)
            ta[0][0] = 0;
         if (k == 2)
            ta[0][2] = 0;
         if (k == 3)
            ta[2][2] = 0;
      }
      if (bn == 5)
      {
         if (k == 0)
            ta[0][3] = ta[2][0] = ta[2][1] = ta[3][1] = ta[3][0] = 0;
         if (k == 1)
            ta[0][0] = ta[1][0] = ta[0][1] = ta[1][1] = ta[3][3] = 0;
         if (k == 2)
            ta[3][0] = ta[0][2] = ta[0][3] = ta[1][2] = ta[1][3] = 0;
         if (k == 3)
            ta[0][0] = ta[2][2] = ta[2][3] = ta[3][2] = ta[3][3] = 0;
      }
      for (i = 0; i <= 2 + add; i++)
         for (j = 0; j <= 2 + add; j++)
            if (ta[i][j] != 1)
               l++;
      if (l == 9 + add * 7)
      {
         change(1);
         for (i = 0; i <= 22; i++)
            for (j = 1; j <= 15; j++)
               if (a[i][j] == 2)
                  a[i][j] = 0;
         for (i = 0; i <= 2 + add; i++)
            for (j = 0; j <= 2 + add; j++)
               if (turn[i][j] == 2)
                  a[x + i][y + j] = turn[i][j];
         shape++;
      }
      if (shape > 3)
         shape = 0;
      appear();
   }
}
int main()
{
   int k, start, finish, d;
   printf("┌");
   for (i = 1; i <= 15; i++)
      printf("┄");
   printf("┐\n");
   for (i = 1; i <= 20; i++)
      printf("┆\n");
   printf("└");
   for (i = 1; i <= 15; i++)
      printf("┄");
   printf("┘");
   for (i = 1; i <= 20; i++)
   {
      Place(i, 32);
      printf("┆\n");
   }
   Place(2, 37);
   printf("下一个");
   Place(8, 37);
   printf("得分");
   Place(14, 37);
   printf("最高分");
   Place(11, 37);
   printf("速度");
   for (i = 0; i <= 2; i++)
      button(i);
   while (ok == 1)
      click();
   while (ok != 1)
   {
      replace();
      next();
      while (1)
      {
         born();
         next();
         while (1)
         {
            appear();
            k = 0;
            start = clock();
            while (1)
            {
               finish = clock();
               d = finish - start;
               if (d >= tim)
                  break;
               control();
               click();
               if (ok == 2)
                  break;
            }
            if (ok == 2)
               break;
            disappear();
            for (i = 22; i >= 0; i--)
               for (j = 1; j <= 15; j++)
                  if (a[i][j] == 2 && a[i + 1][j] != 1)
                     k++;
            if (k == 4)
            {
               for (i = 22; i >= 0; i--)
                  for (j = 1; j <= 15; j++)
                     if (a[i][j] == 2)
                     {
                        a[i + 1][j] = 2;
                        a[i][j] = 0;
                     }
            }
            else
            {
               for (i = 22; i >= 0; i--)
                  for (j = 1; j <= 15; j++)
                     if (a[i][j] == 2)
                        a[i][j] = 1;
               break;
            }
            tim = ti;
            appear();
         }
         if (ok == 2)
            break;
         appear();
         clear();
         ss();
         for (i = 1; i <= 15; i++)
            if (a[2][i] == 1)
            {
               ok = 1;
               break;
            }
      }
      if (ok == 2)
      {
         ok = 0;
         continue;
      }
      for (i = 1; i <= 20; i++)
         for (j = 2; j <= 30; j++)
         {
            Place(i, j);
            printf(" ");
         }
      Place(9, 12);
      printf("游戏结束!");
      while (ok == 1)
         click();
   }
   return 0;
}