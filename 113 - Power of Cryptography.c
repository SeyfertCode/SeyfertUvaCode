//LAXUS-Seyfert
#include<math.h>
#include <stdio.h>

int main()
{
    double n, p, k;
    while (scanf("%lf %lf", &n, &p) == 2) {
        k = exp(log(p)/n);
        printf("%.0lf\n", k);
    }
}
