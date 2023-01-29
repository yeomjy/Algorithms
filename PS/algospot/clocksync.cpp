#include <iostream>
#include <vector>

using namespace std;

int solve(int tc[], int clocks[]);
bool check(int tc[]);
int *nextClocks(int clocks[]);
bool maximum(int clocks[]);
int main()
{

    int C;
    int tc[16];
    int clocks[10] = {
        0,
    };
    int ans = -1;
    cin >> C;
    for (int _count = 0; _count < C; _count++)
    {
        ans = -1;
        for (int i = 0; i < 16; ++i)
            cin >> tc[i];
        for (int i = 0; i < 10; ++i)
            clocks[i] = 0;
        for (int i = 0; i < 1048576; ++i)
        {
            int temp = solve(tc, clocks);
            if (temp >= 0 && (temp <= ans || ans == -1))
                ans = temp;
            nextClocks(clocks);
        }
        cout << ans << endl;
    }
    return 0;
}
int *nextClocks(int clocks[])
{
    clocks[0] += 1;
    for (int i = 0; i < 9; ++i)
    {
        if (clocks[i] == 4)
        {
            clocks[i] = 0;
            clocks[i + 1]++;
        }
    }
    return clocks;
}

bool maximum(int clocks[])
{
    bool ans = true;
    for (int i = 0; i < 10; ++i)
    {
        ans = ans && (clocks[i] == 3);
    }
    return ans;
}

bool check(int tc[])
{
    bool ans = true;
    for (int i = 0; i < 16; ++i)
    {
        ans = ans && (tc[i] == 12);
    }
    return ans;
}

int solve(int tc[], int clocks[])
{

    int ans = 0;

    bool c;

    int copied_tc[16];
    for (int i = 0; i < 16; ++i)
    {
        copied_tc[i] = tc[i];
    }

    int switch_list[10][5] = {
        {0, 1, 2, -1, -1},
        {3, 7, 9, 11, -1},
        {4, 10, 14, 15, -1},
        {0, 4, 5, 6, 7},
        {6, 7, 8, 10, 12},
        {0, 2, 14, 15, -1},
        {3, 14, 15, -1, -1},
        {4, 5, 7, 14, 15},
        {1, 2, 3, 4, 5},
        {3, 4, 5, 9, 13}};

    for (int i = 0; i < 10; ++i)
    {
        switch (clocks[i])
        {
        case 0:
            break;

        case 1:
            for (int k = 0; k < 5; ++k)
            {
                int j = switch_list[i][k];
                if (j == -1)
                    continue;
                else
                {
                    copied_tc[j] = (copied_tc[j] + 3);
                    if (copied_tc[j] > 12)
                        copied_tc[j] = copied_tc[j] - 12;

                    c = check(copied_tc);
                    if (c)
                    {
                        break;
                    }
                }
            }
            ans += 1;
            if (c)
                return ans;
            break;

        case 2:
            for (int k = 0; k < 5; ++k)
            {
                int j = switch_list[i][k];
                if (j == -1)
                    continue;
                else
                {
                    copied_tc[j] = (copied_tc[j] + 6);
                    if (copied_tc[j] > 12)
                        copied_tc[j] = copied_tc[j] - 12;

                    c = check(copied_tc);
                    if (c)
                    {
                        break;
                    }
                }
            }
            ans += 2;
            if (c)
                return ans;
            break;

        case 3:
            for (int k = 0; k < 5; ++k)
            {
                int j = switch_list[i][k];
                if (j == -1)
                    continue;
                else
                {
                    copied_tc[j] = (copied_tc[j] + 9);
                    if (copied_tc[j] > 12)
                        copied_tc[j] = copied_tc[j] - 12;

                    c = check(copied_tc);
                    if (c)
                    {
                        break;
                    }
                }
            }
            ans += 3;
            if (c)
                return ans;
            break;
        default:
            break;
        }
    }
    if (!c)
    {
        return -1;
    }

    return ans;
}
