#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int T;

    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N;
        int P;
        cin >> N;
        cin >> P;
        vector<int> h(P);
        set<int> s;

        for (int i = 0; i < P; i++)
            cin >> h[i];

        for (int i = 0; i < N; i++)
        {
            if (i % 7 == 5 || i % 7 == 6)
                continue;
            for (int j = 0; j < P; j++)
            {
                if ((i + 1) % h[j] == 0)
                    s.insert(i + 1);
            }
        }
        cout << s.size() << "\n";
    }
}