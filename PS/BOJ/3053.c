#include <stdio.h>

int main()
{
    double x;
    scanf("%lf", &x);

    printf("%lf\n%lf", 3.14159265 * x * x, 2.0 * x * x);
}
