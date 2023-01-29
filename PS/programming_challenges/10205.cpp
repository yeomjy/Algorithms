// #include <deque>
#include <string>
#include <iostream>
// #include <cstdio>
// #include <sstream>
#include <vector>

using namespace std;

int main()
{
    int tc;

    cin >> tc;
    // scanf("%d", &tc);
    // cout << tc << "\n\n";

    for (int i = 0; i < tc; i++)
    {
        int n;
        vector<int> v(52);
        // string s;
        int s;

        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 13; k++)
            {
                if (k == 12)
                {
                    v[j * 13 + k] = 0 + 13 * j;
                }
                else
                {
                    v[j * 13 + k] = k + 1 + 13 * j;
                }
            }
        }

        cin >> n;
        // scanf("%d", &n);
        vector<vector<int>> map(n, vector<int>(52));

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 52; k++)
            {

                cin >> map[j][k];
                // scanf("%d", &map[j][k]);
                map[j][k] -= 1;
                // cout << "Read " << j << "th line " << k << "th number: " << map[j][k] + 1 << "\n";
            }
        }
        // for (int j = 0; j < n; j++)
        // {
        //     for (int k = 0; k < 52; k++)
        //     {
        //         cout << map[j][k] + 1 << " ";
        //     }
        //     cout << "\n";
        // }
        // break;
        vector<int> l;
        cin.ignore();
        char buf[200];

        while (true)
        {
            cin.getline(buf, 200);
            if (buf[0] == '\0' || buf[0] == '\n')
                break;

            // cout << "Segfault? " << buf << "\n";

            l.push_back(stoi(buf) - 1);
        }

        for (int d : l)
        {
            vector<int> buf(52);
            for (int k = 0; k < 52; k++)
            {
                buf[k] = v[map[d][k]];
            }
            for (int k = 0; k < 52; k++)
            {
                v[k] = buf[k];
            }
        }

        for (int j = 0; j < 52; j++)
        {
            int card = v[j];
            string s, name;
            switch (card / 13)
            {
            case 0:
                s = "Clubs";
                break;
            case 1:
                s = "Diamonds";
                break;
            case 2:
                s = "Hearts";
                break;

            case 3:
                s = "Spades";
                break;

            default:
                break;
            }
            switch (card % 13)
            {
            case 0:
                name = "Ace";
                break;
            case 10:
                name = "Jack";
                break;
            case 11:
                name = "Queen";
                break;
            case 12:
                name = "King";
                break;
            default:
                name = to_string(card % 13 + 1);
                break;
            }
            cout << name << " of " << s << "\n";
            // printf("%s of %s\n", name, s);
        }
        if (i < tc - 1)
            cout << "\n";
        // printf("\n");
    }
}