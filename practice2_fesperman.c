#include <stdio.h>

int main() {
    //
    int num, rnum, rnum2, rnum3, sum;
    char ch1, ch2, ch3, alpha;
    alpha = 'A';
    printf("Enter Number:");
    scanf("%d", &num);
    rnum = num % 10;
    rnum2 = num / 10 % 10;
    rnum3 = num / 100;
    ch1 = (char)(rnum3) + alpha;
    ch2 = (char)(rnum2) + alpha;
    ch3 = (char)(rnum) + alpha;
    rnum = rnum *100 + rnum2 *10 + rnum3;
    printf("Reversed: %d", rnum);
    sum = num + rnum;
    printf("\nSum: %d", sum);
    printf("\nHidden Code: %c%c%c", ch3, ch2, ch1);
    
    //
    return 0;
}
