#include <stdio.h>
#include <string.h>

int main(void)
{
    char x[100000], y[100000], ans[100000];

    scanf("%s",&x);
    scanf("%s",&y);
    int c_x = strlen(x)- 1,c_y = strlen(y) - 1, count, t = 0,lastx,lasty,num,i = 0;
    if (c_x > c_y)
        count = c_x + 1;
    else
        count = c_y + 1;
    for (i ; i <=count ; i++)
    {
        if (c_x >= 0)
            lastx = x[c_x];
        else
            lastx = '0';
        if (c_y >= 0)
            lasty= y[c_y];
        else
            lasty = '0';
        num = (lastx-'0') + (lasty-'0') + t;
        t = 0;
        if (num > 9)
            t = 1;
        ans[99999 - i] = (num % 10) + '0';
        c_x--;
        c_y--;
    }
    if (ans[99999-i+1] == '0')
        i--;
    for (int n = 0; n < i; n++)
    {
        printf("%c",ans[99999-i+1+n]);
    }
}