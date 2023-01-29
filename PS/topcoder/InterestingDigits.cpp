#include <cstdio>
#include <vector>

using namespace std;

class InterestingDigits
{
public:
    vector<int> digits(int base);
};

vector<int> InterestingDigits::digits(int base)
{
    // int arr[3] = {0};
    vector<int> ans;
    for (int n = 2; n < base; n++)
    {
        bool istrue = true;
        for (int i1 = 0; i1 < base; i1++)
        {
            for (int i2 = 0; i2 < base; i2++)
            {
                for (int i3 = 0; i3 < base; i3++)
                {
                    int num = i1;
                    num = num * base + i2;
                    num = num * base + i3;
                    istrue = istrue && ((i1 + i2 + i3) % n == 0) && (num % n == 0);
                }
            }
        }
        if (istrue)
            ans.push_back(n);
    }
}
