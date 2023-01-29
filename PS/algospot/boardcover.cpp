#include <iostream>
#include <utility>

// #define isIN(x, a, b) (((x) >= (a) && (x) < (b)) ? true : false)

using namespace std;

int ans;
void solve(int gameBoard[20][20], int H, int W, int blank);

int main()
{
    int C, H, W;
    cin >> C;
    for (int testCase = 0; testCase < C; testCase++)
    {
        // init
        ans = 0;
        int gameBoard[20][20];
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                gameBoard[i][j] = -1;
        // get input
        cin >> H >> W;
        char temp;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> temp;
                if (temp == '#')
                    gameBoard[i][j] = 1;
                else
                    gameBoard[i][j] = 0;
            }
            if (i != H - 1)
                cin.get();
        }
        int blank = 0;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (gameBoard[i][j] == 0)
                    blank++;

        if (blank % 3 != 0 || blank == 0)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            solve(gameBoard, H, W, blank);
            cout << ans << endl;
        }
    }
}

void solve(int gameBoard[20][20], int H, int W, int blank)
{
    if (blank == 0)
    {
        ans++;
        return;
    }

    else
    {
        // find the first case
        std::pair<int, int> firstCase;
        bool isExist = false;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (isExist)
                    break;
                if (gameBoard[i][j] == 0)
                {
                    firstCase.first = i;
                    firstCase.second = j;
                    isExist = true;
                    break;
                }
            }
        }
        if (isExist)
        {
            int i = firstCase.first;
            int j = firstCase.second;
            // cout << "(i, j) = (" << i << ", " << j << ")\n";
            if (j + 1 < W && i + 1 < H && gameBoard[i][j + 1] == 0 && gameBoard[i + 1][j + 1] == 0)
            {
                gameBoard[i][j] = gameBoard[i][j + 1] = gameBoard[i + 1][j + 1] = 1;
                solve(gameBoard, H, W, blank - 3);
                gameBoard[i][j] = gameBoard[i][j + 1] = gameBoard[i + 1][j + 1] = 0;
            }
            if (j + 1 < W && i + 1 < H && gameBoard[i + 1][j] == 0 && gameBoard[i + 1][j + 1] == 0)
            {
                gameBoard[i][j] = gameBoard[i + 1][j] = gameBoard[i + 1][j + 1] = 1;
                solve(gameBoard, H, W, blank - 3);
                gameBoard[i][j] = gameBoard[i + 1][j] = gameBoard[i + 1][j + 1] = 0;
            }
            if (j - 1 >= 0 && i + 1 < H && gameBoard[i + 1][j] == 0 && gameBoard[i + 1][j - 1] == 0)
            {
                gameBoard[i][j] = gameBoard[i + 1][j] = gameBoard[i + 1][j - 1] = 1;
                solve(gameBoard, H, W, blank - 3);
                gameBoard[i][j] = gameBoard[i + 1][j] = gameBoard[i + 1][j - 1] = 0;
            }
            if (j + 1 < W && i + 1 < H && gameBoard[i + 1][j] == 0 && gameBoard[i][j + 1] == 0)
            {
                gameBoard[i][j] = gameBoard[i][j + 1] = gameBoard[i + 1][j] = 1;
                solve(gameBoard, H, W, blank - 3);
                gameBoard[i][j] = gameBoard[i][j + 1] = gameBoard[i + 1][j] = 0;
            }
        }
        else
            return;
    }
}
