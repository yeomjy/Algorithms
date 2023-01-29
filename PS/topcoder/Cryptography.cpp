//
// Created by yeomj on 2022-06-24.
//
#include <vector>
#include <set>

using namespace std;

class Cryptography {
private:
    long long product(vector<int> &numbers, int incr);
public:
    long long encrypt(vector<int> numbers);
};

long long Cryptography::product(vector<int> &numbers, int incr) {
    long long prod = 1;
    int n = numbers.size();
    for (int i =0; i < n; i++)
    {
        if (numbers[i] == incr)
        {
            prod *= (incr + 1);
            incr = 0;
        }
        else
            prod *= numbers[i];
    }
    return prod;
}

long long Cryptography::encrypt(vector<int> numbers) {
    // 0, 1, ..., 9
    set<int> int_set;
    int n = numbers.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int_set.insert(numbers[i]);
    }

    long long ans = 0;
    long long prod = 0;
    for (int i : int_set)
    {
        prod = Cryptography::product(numbers, i);
        if (prod > ans)
            ans = prod;
    }
    return ans;
}
