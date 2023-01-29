#include <iostream>

using namespace std;

int main() 
{
    int m, n;
    char board[100][100];
    char ans[100][100];
    int buf[100][100];
    int field_num = 1;
        
    while(true) {
        cin >> n >> m;
        if (m==0 && n == 0)
            break;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> board[i][j];
                buf[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == '*')
                    ans[i][j] = '*';
                else 
                {
                    for (int dx = -1; dx <= 1; dx++)  
                    {
                        for (int dy = -1; dy <= 1; dy++) 
                        {
                            if (i + dy < 0 || j + dx < 0 || i + dy >= n || j + dx >= m)
                                continue;
                            else
                                if (board[i + dy][j+dx] == '*')
                                    buf[i][j]++;
                        }
                    }
                    ans[i][j] = buf[i][j] + '0';
                }
            }
        }
        if (field_num > 1)
            cout << "\n";
        cout << "Field #" << field_num << ":\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cout << ans[i][j];
            cout << "\n";
        }
        field_num++;

    }
}
