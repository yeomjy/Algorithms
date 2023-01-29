#include <algorithm>
#include <cstdio>
#include <vector>

using std::vector;

int main()
{
    int numberOfTestCase = 0;
    int numberOfDays = 0;
    int numberOfTeams = 0;
    int temp = 0;
    double tempaverage = 0.0;
    vector<int> Price(0, 0);
    vector<double> Answer(0, 0.0);

    scanf("%d", &numberOfTestCase);
    for (size_t i = 0; i < numberOfTestCase; ++i)
    {
        double min = __DBL_MAX__;
        Price.clear();
        scanf("%d%d", &numberOfDays, &numberOfTeams);
        for (size_t j = 0; j < numberOfDays; ++j)
        {
            scanf("%d", &temp);
            Price.push_back(temp);
        }

        for (size_t k = numberOfTeams; k <= numberOfDays; ++k)
        {
            for (size_t j = 0; j <= numberOfDays - k; ++j)
            {
                temp = 0;
                for (size_t l = 0; l < k; ++l)
                    temp += Price[l + j];

                tempaverage = temp / (double)k;
                if (tempaverage < min)
                    min = tempaverage;
            }
        }
        Answer.push_back(min);
    }
    for (auto &i : Answer)
        printf("%.8lf\n", i);

    return 0;
}
