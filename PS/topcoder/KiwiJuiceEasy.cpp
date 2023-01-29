#include <cstdio>
#include <vector>

using namespace std;

class KiwiJuiceEasy
{
public:
    vector<int> thePouring(
            vector<int> capacities, 
            vector<int> bottles,
            vector<int> fromId, 
            vector<int> toId
            );
};

vector<int> KiwiJuiceEasy::thePouring(
        vector<int> capacities,
        vector<int> bottles,
        vector<int> fromId,
        vector<int> toId
        )
{
    int n = bottles.size();
    int m = fromId.size();
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        int from = fromId[i];
        int to = toId[i];
        
        if (bottles[from] == 0 || bottles[to] == capacities[to])
            continue;

        if (capacities[to] - bottles[to] > bottles[from])
        {
            bottles[to] += bottles[from];
            bottles[from] = 0;
        } else if (capacities[to] - bottles[to] <= bottles[from]) 
        {
            bottles[from] -= (capacities[to] - bottles[to]);
            bottles[to] = capacities[to];
        }

    }
    return bottles;
}
