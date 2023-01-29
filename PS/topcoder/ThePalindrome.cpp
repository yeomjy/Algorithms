#include <vector>
#include <string>
// #include <cstdio>

using namespace std;

class ThePalindrome
{
public:
    int find(string s);
};

int ThePalindrome::find(string s)
{
    int len = s.length();
    int ans = 0;
    bool case1;
    bool case2;



    for (int loc = len / 2; loc < len; loc++)
    {
        // Case 1:
        // [x... loc-1] loc [loc+1 ... n - 1]
        // [0.. loc - 1] loc [loc+1 ... n - 1] [n ... m-1]
        // m = total length 
        // loc = (m - 1) - (loc + 1) + 1 = m - loc - 1
        // m = 2 * loc + 1
        //
        //
        // Case 2:
        // [x ... loc-1] [loc... n-1] [n ... m-1]
        // m = 2 * loc
        case1=true;
        case2=true;

        for (int i = 0; loc + i < len; i++)
        {
            if (s[loc - i] != s[loc + i])
            {
                case1=false;
            }
            if (s[loc + i] != s[loc - i - 1])
            {
                case2=false;
            }
            if (!case1 && !case2)
                break;
        }
        if (case2)
        {
            ans = 2 * loc;
            break;
        }
        else if (case1)
        {
            ans = 2 * loc + 1;
            break;
        }
    }
    return ans;
}

/*
int main() 
{
    ThePalindrome t;
    
    printf("%d\n", t.find("abab"));
    printf("%d\n", t.find("abacaba"));
    printf("%d\n", t.find("qwerty"));
    printf("%d\n", t.find("abcccc"));
    printf("%d\n", t.find("abdfhdyrbdbsdfghjkllkjhgfds"));
}
*/
