#include <algorithm>
#include <iostream>
#include <vector>

void GeneratePermutation(std::vector<std::vector<int>> &SymmetricGroup, int n);

int factorial(int n);
int main(void)
{
    int n;
    std::vector<std::vector<int>> SymmetricGroup(0, std::vector<int>(0, 0));
    std::cin >> n;
    GeneratePermutation(SymmetricGroup, n);
    int j = 1;
    std::sort(SymmetricGroup.begin(), SymmetricGroup.end());
    for (auto i : SymmetricGroup)
    {
        switch (j)
        {
        case 1:
            std::cout << j << "st Case: ";
            break;
        case 2:
            std::cout << j << "nd Case: ";
            break;
        case 3:
            std::cout << j << "rd Case: ";
            break;
        default:
            std::cout << j << "th Case: ";
            break;
        }
        for (auto k : i)
            std::cout << k << ' ';
        std::cout << '\n';
        j++;
    }
    return 0;
}

void GeneratePermutation(std::vector<std::vector<int>> &SymmetricGroup, int n)
{
    std::vector<int> tempVector(0, 0);
    if (n == 0)
        return;
    else if (n == 1)
    {
        tempVector.push_back(1);
        SymmetricGroup.push_back(tempVector);
        tempVector.clear();
        return;
    }
    else
    {
        GeneratePermutation(SymmetricGroup, n - 1);
        int length = factorial(n - 1);
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < length; ++j)
            {
                tempVector.clear();
                for (auto k : SymmetricGroup[j])
                    tempVector.push_back(k);
                SymmetricGroup.push_back(tempVector);
            }
        for (auto &i : SymmetricGroup)
            i.push_back(n);

        for (int i = 0; i < length; i++)
            for (int j = 0; j < n; j++)
                std::swap(SymmetricGroup[i + length * j][j], SymmetricGroup[i + length * j][n - 1]);
        return;
    }
}

int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; ++i)
        res *= i;
    return res;
}
