#include <stdio.h>
#include <ctype.h>
#include <time.h>
    int get_random_number(void);
    int main(void) {
    //
    srand(time(NULL));
    int i,num,N;
    printf("Enter N: ");
    scanf("%d", &N);
    for(i=1;i<=N;i++){
        num = get_random_number();
        printf("#%d: %d\n", i, num);
        }
    //
    return 0;
    }
    int get_random_number(void){
        int num = rand()%(9)+1;
        return num;

    }
