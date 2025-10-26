#include <stdio.h>

int main() {
    //
    double fnum,snum;
    double sum,dif,prod,quo;
    printf("Enter the first number: ");
    scanf("%lf",&fnum);
    printf("Enter the second number: ");
    scanf("%lf",&snum);
    sum = fnum + snum;
    printf("\nSum: %.4lf", sum);
    dif = fnum - snum;
    printf("\nDifference: %.4lf", dif);
    prod = fnum * snum;
    printf("\nProduct: %.4lf", prod);
    if(snum !=0){
        quo =  fnum / snum;
        printf("\nQuotient: %.4lf\n", quo);
    }
    else{ 
        printf("\nQuotient: DNE\n");
    }
    //
    return 0;
}
