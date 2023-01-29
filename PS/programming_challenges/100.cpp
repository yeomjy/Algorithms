#include <iostream>

using namespace std;

int cycle_len(int i)
{
    int k = 1;
    while (i != 1)
    {
        if (i % 2 == 0) 
            i /= 2;
        else
            i = 3 * i + 1;
        k++;
    }
    return k;
}


int main() 
{
   int i, j;
   int input_i, input_j;

   while (true)
   {
       cin >> input_i >> input_j;
       if (cin.eof())
           break;

       if (input_i > input_j) {
           i = input_j;
           j = input_i;
       } else {
           i = input_i;
           j = input_j;
       }
           
       
       int max_val = cycle_len(i);
       for (int idx = i + 1; idx <= j; ++idx)
       {
            int count = cycle_len(idx);
            if (count > max_val)
                max_val = count;
       }
       cout << input_i << " " << input_j << " " << max_val << "\n";
   }
}
