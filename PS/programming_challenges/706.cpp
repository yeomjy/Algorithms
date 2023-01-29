#include <cstdio>
#include <cstring>

void print(int arr[10], int n, int s);

int main()
{
    int arr[10];
    char buf[10];
    int a, s, n;

    while (scanf("%d %s", &s, buf) != EOF)
    {

        if (s == 0)
            break;
        n = strlen(buf);
        for (int i = 0; i < n; i++)
        {
            arr[i] = (int)(buf[i] - '0');
        }
        print(arr, n, s);
    }

    return 0;
}

void print(int arr[10], int n, int s)
{
    for (int i = 0; i < 2 * s + 3; i++)
    {
        for (int k = 0; k < n; k++)
        {
            int x = arr[k];
            // print ith line of x

            if (i == 0 || i == 2 * s + 2)
            {
                if (x == 1 || x == 4 || (x == 7 && i == 2 * s + 2))
                {
                    for (int j = 0; j < s + 2; j++)
                        putchar(' ');
                }
                else
                {
                    putchar(' ');
                    for (int j = 0; j < s; j++)
                        putchar('-');
                    putchar(' ');
                }
            }
            else if (i == s + 1)
            {
                if (x == 1 || x == 7 || x == 0)
                {
                    for (int j = 0; j < s + 2; j++)
                        putchar(' ');
                }
                else
                {
                    putchar(' ');
                    for (int j = 0; j < s; j++)
                        putchar('-');
                    putchar(' ');
                }
            }
            else if (i < s + 1)
            {
                if (x == 1 || x == 2 || x == 3 || x == 7)
                {
                    // 오른쪽
                    for (int j = 0; j < s + 1; j++)
                        putchar(' ');
                    putchar('|');
                }
                else if (x == 5 || x == 6)
                {
                    // 왼쪽
                    putchar('|');
                    for (int j = 0; j < s + 1; j++)
                        putchar(' ');
                }
                else
                {
                    // 양쪽
                    putchar('|');
                    for (int j = 0; j < s; j++)
                        putchar(' ');
                    putchar('|');
                }
            }
            else
            {
                if (x == 1 || x == 3 || x == 4 || x == 5 || x == 7 || x == 9)
                {
                    // 오른쪽
                    for (int j = 0; j < s + 1; j++)
                        putchar(' ');
                    putchar('|');
                }
                else if (x == 2)
                {
                    // 왼쪽
                    putchar('|');
                    for (int j = 0; j < s + 1; j++)
                        putchar(' ');
                }
                else
                {
                    // 양쪽
                    putchar('|');
                    for (int j = 0; j < s; j++)
                        putchar(' ');
                    putchar('|');
                }
            }
            if (k < n - 1)
                putchar(' ');
        }
        putchar('\n');
    }
    putchar('\n');
}
