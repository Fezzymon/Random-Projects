#include <stdio.h>
#define Digit_Count 5
void populate_array(int arr[], int size, int num);
void print_array(int arr[], int size);
int get_next_pos(int cur_pos, int size, int shift);
void left_shift_array(int arr[], int size, int shift);
int main(void){
    int T,digits[Digit_Count],shift,num;
    printf("How many Test-Cases: ");
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&num);
        populate_array(digits,Digit_Count,num);
        scanf("%d",&shift);
        left_shift_array(digits,Digit_Count,shift);
        printf("%d: ", i);
        print_array(digits,Digit_Count);
        printf("\n");
    }
    return 0;
}
void populate_array(int arr[], int size, int num){
    //populate array of size with rightmost digits of num
    for(int i=size-1; i>=0;i--){
        arr[i] = num%10;
        num = num / 10;
    }
}
void print_array(int arr[], int size){
    //helper function to print contents of array
    for(int i=0;i<size;i++){
        printf("%d", arr[i]);
    }
}
int get_next_pos(int cur_pos, int size, int shift){
    // Given the destination 'cur_pos', find the index to READ FROM.
    // For a left shift, the element to read from is 'shift' positions ahead.
    return (cur_pos + shift) % size;
}
void left_shift_array(int arr[], int size, int shift){
    // Perform a cycle walk to rotate the array in place to the left by shift positions.

    // Calculate the effective shift
    shift = shift % size;

    // If shift is 0, no operation is needed.
    if (shift == 0) {
        return;
    }

    // In-place cycle walk implementation:
    // This structure will work for size=5 where gcd(5, shift) is always 1.
    int start_pos = 0;
    int cur_pos = start_pos;
    int next_pos;
    int temp; // Holds the value to be moved into the current 'cur_pos'

    // 1. Store the value that will be overwritten first.
    temp = arr[cur_pos];

    // 2. Perform the cycle walk until we return to start_pos.
    // We only move 'size' elements in total.
    for (int i = 0; i < size; i++) {
        // Find the index to read FROM.
        next_pos = get_next_pos(cur_pos, size, shift);

        if (next_pos == start_pos) {
            // We have completed the cycle.
            // The value we stored (temp) is placed in the final position (cur_pos).
            arr[cur_pos] = temp;
            break;
        }

        // Move the value from next_pos to the current cur_pos.
        arr[cur_pos] = arr[next_pos];

        // The destination for the next step is the current next_pos.
        cur_pos = next_pos;
    }
}
