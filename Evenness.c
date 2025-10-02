#include <stdio.h>
#include <ctype.h>
#include <time.h>
    void is_even(N);
    int main(void) {
    //
    int i,num,N;
    printf("Enter N: ");
    scanf("%d", &N);
    is_even(N);

    //
    return 0;
    }
    void is_even(N){
        if(N%2 == 0){
            printf("N is Even\n");
        }else{
            printf("N is Odd\n");
        }
        return 1;

    }
