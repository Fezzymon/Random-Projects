#include <stdio.h>
#include <ctype.h>
int is_palindrome(int num);
int get_reverse(int num);

int main(void) {
    //
    int T,i,num;
    printf("How many test cases: ");
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d",&num);
        printf("%d: %d %d %d\n", i, num, get_reverse(num), is_palindrome(num));
    }
    //
    return 0;
}
int get_reverse(num){
    int rev_num = 0, remainder;
    while (num>0){

        remainder = num % 10;

        rev_num = rev_num * 10 + remainder;

        num = num/10;
    }
        return rev_num;

    }
int is_palindrome(int num){
    int num_rev = get_reverse(num);

return num == num_rev;

}




