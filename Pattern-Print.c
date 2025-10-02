#include <stdio.h>
#include <ctype.h>
int main() {
    //
    int N, i, j;
    printf("Enter N: ");
    scanf("%d", &N);
    for(i=0;i<=N;i++){
        for(j=N-i;j>0;j--){
            printf("*");
            continue;
        }
    printf("\n");
    }
    //
    return 0;
}
