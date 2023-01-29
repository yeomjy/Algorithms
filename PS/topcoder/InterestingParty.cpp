//
// Created by yeomj on 2022-06-24.
//

#include <cstdio>
#include <string>
#include <vector>
#include <set>

using namespace std;


class InterestingParty {
public:
    int bestInvitation(vector<string> first, vector<string> second);
};

int InterestingParty::bestInvitation(vector<string> first, vector<string> second) {
    int max = 0;
    int n = first.size();
    set<string> topic_set;

    for (int i = 0; i < n; i++)
    {
        topic_set.insert(first[i]);
        topic_set.insert(second[i]);
    }

    for (string topic: topic_set)
    {
        int n_friends = 0;
        for (int i = 0; i < n; i++)
        {
            if (topic == first[i] || topic == second[i])
            {
                n_friends++;
            }
        }
        if (n_friends > max)
            max = n_friends;
    }
    return max;
}
