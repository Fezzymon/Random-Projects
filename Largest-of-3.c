#include <stdio.h>
#include <ctype.h>
int main() {
    //
    int i, N[3],big;
    printf("Enter 3 Numbers: ");
    for(i=0;i<3;i++){
        scanf("%d", &N[i]);
    }
    big = N[0];
    if(N[1]>big){
        big = N[1];
    }if(N[2]>big){
        N[2]=big;
    }
    printf("%d is the largest number.", big);
    //
    return 0;
}
