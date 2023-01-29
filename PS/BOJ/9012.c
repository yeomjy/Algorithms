#include <stdio.h>

int main()
{
    int T;
    char k;
    char x[100];
    int ans;
    scanf("%d\n", &T);

    for (int num = 0; num < T; ++num)
    {
        ans = 0;
        int len = 0;
        while ((k = getchar()) != '\n' && k != EOF)
        {
            x[len] = k;
            len++;
        }
        for (int i = 0; i < len; ++i)
        {
            if (x[i] == '(')
                ans++;
            else if (x[i] == ')')
                ans--;
            else
                break;
            if (ans < 0)
                break;
        }
        if (ans != 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
