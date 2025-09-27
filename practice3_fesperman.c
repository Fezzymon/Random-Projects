#include <stdio.h>
#include <ctype.h>
int main() {
    //
    int N,chval;
    char input;
    printf("Enter N: ");
    scanf("%d", &N);
    for(int count = 1; count<=N; count++){
        printf("Enter a Alphabetical Character: ");
        scanf(" %c", &input);
        printf("%d: ",count);
        if(isalpha(input)){
            chval = toupper(input) - 'A' + 1;
            printf("%d\n",chval);
             }
        else{
            printf("Invalid\n");
            }
        continue;
        }

    //
    return 0;
}
