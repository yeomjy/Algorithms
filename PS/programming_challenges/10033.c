#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    int reg[10] = {0};
    int ram[1000] = {0};
    char cmd[100];
    int d, n, s, a;

    int pc;
    int i;

    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%s", &cmd);
        int count = 0;
        int cmd_int;
        int done = 0;
        memset(reg, 0, 10);
        memset(ram, 0, 1000);

        while (1)
        {
            count++;
            // if (strcmp(cmd, "100") == 0)
            //     break;

            cmd_int = (int)(cmd[0] - '0');

            switch (cmd_int)
            {
            case 1:
                done = 1;
                break;
            case 2:
                d = (int)(cmd[1] - '0');
                n = (int)(cmd[2] - '0');

                reg[d] = n;

                break;
            case 3:
                d = (int)(cmd[1] - '0');
                n = (int)(cmd[2] - '0');

                reg[d] += n;
                reg[d] %= 1000;

                break;
            case 4:
                d = (int)(cmd[1] - '0');
                n = (int)(cmd[2] - '0');

                reg[d] *= n;
                reg[d] %= 1000;

                break;
            case 5:
                d = (int)(cmd[1] - '0');
                s = (int)(cmd[2] - '0');

                reg[d] = reg[s];

                break;
            case 6:
                d = (int)(cmd[1] - '0');
                s = (int)(cmd[2] - '0');

                reg[d] += reg[s];
                reg[d] %= 1000;

                break;
            case 7:
                d = (int)(cmd[1] - '0');
                s = (int)(cmd[2] - '0');

                reg[d] *= reg[s];
                reg[d] %= 1000;

                break;
            case 8:
                d = (int)(cmd[1] - '0');
                a = (int)(cmd[2] - '0');

                reg[d] = ram[reg[a]];

                break;
            case 9:
                s = (int)(cmd[1] - '0');
                a = (int)(cmd[2] - '0');

                ram[reg[a]] = reg[s];

                break;
            case 0:
                d = (int)(cmd[1] - '0');
                s = (int)(cmd[2] - '0');

                if (reg[s] != 0)
                    pc = reg[d];

                break;

            default:
                break;
            }

            if (done)
                break;
        }
        printf("%d\n", count);
    }
}