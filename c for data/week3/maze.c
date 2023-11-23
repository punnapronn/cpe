#include <stdio.h>
#include <stdlib.h>

void maze(char **a,int s_r,int s_c,int n)
{
    int di[4][2] = {{0,1},{-1,0},{1,0},{0,-1}};

    for (int i = 0; i < 4; i++)
    {
        if (s_r + di[i][0] < 0 || s_r + di[i][0] > n - 1 || s_c + di[i][1] < 0 || s_c + di[i][1] > n - 1)
            continue;
        if (a[s_r + di[i][0]][s_c + di[i][1]] == 'G')
        {
            a[s_r][s_c] = '.';
            for (int j = 0; j < n; j++)
                printf("%s\n", a[j]);
        }
        if (a[s_r + di[i][0]][s_c + di[i][1]] == ' ')
        {
            if (a[s_r][s_c] != 'S')
                a[s_r][s_c] = '.';
            maze(a, s_r + di[i][0], s_c + di[i][1], n);
            a[s_r][s_c] = ' ';
        }
    }
}

int main(void)
{
    char **a ,*str, j;
    int n;
    int s_r,s_c;

    scanf("%d ", &n);
    a = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        j = 0;
        a[i] = (char *)malloc(sizeof(char) * n + 2);
        fgets(a[i],n + 2,stdin);
        a[i][n] = '\0';
        while (a[i][j])
        {
            if (a[i][j] == 'S')
            {
                s_r = i;
                s_c = j;
            }
            j++;
        }

    }
    maze(a, s_r, s_c, n);
}