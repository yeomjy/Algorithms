#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    set<string> dict;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        dict.insert(s);
    }

    while (true)
    {
        vector<string> s_vector;
        vector<string> dec;
        string buffer;
        char buf[100];
        cin.getline(buf, 99);
        s = buf;
        if (cin.eof())
            break;
        istringstream ss(s);

        while (getline(ss, buffer, ' '))
        {
            s_vector.push_back(buffer);
        }

        int len = s_vector.size();
        bool decrypted;

        if (!decrypted)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ' ')
                    cout << ' ';
                else
                    cout << '*';
            }
            cout << "\n";
        }
        else
        {
            for (int i = 0; i < dec.size(); i++)
            {
                cout << dec[i];
                if (i < dec.size() - 1)
                {
                    cout << ' ';
                }
                else
                {
                    cout << "\n";
                }
            }
        }
    }
}