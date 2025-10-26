#include <stdio.h>
#include <ctype.h>
#include <time.h>
#define MAX_COUNT 10
    void print_array(int arr[], int size);
    int compress_array(int arr[], int size);
    int shift_array(int arr[], int size, int index);
    int main(void) {
    //
    int T;//get number of test cases
    printf("Enter Number of Test Cases: ");
    scanf("%d", &T);
    int nums[MAX_COUNT];
    for(int i=1;i<=T;i++){
        int count=0;//actual count of numbers
        for(int j=0;j<MAX_COUNT;j++,count++){
            printf("Enter #%d: ", j+1);
            //read number
            scanf("%d", &nums[j]);
            //if sentinel is reached, exit inner loop
            if(nums[j]==0) break;
        }
        //compress the array and pass actual count
        count = compress_array(nums, count);

        //print test case info
        printf("%d: ", i);

        //print contents of array after changes
        print_array(nums, count);
    }


    //
    return 0;
    }
void print_array(int arr[], int size){
    for(int i =0;i<size;i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}
int compress_array(int arr[], int size){
    //edge case: when array is empty
    if(size == 0) return 0;
    int prev = arr[0];
    int pos = 1;
    //while still elements to process
    while(pos<size){
        //is there a duplicate?
        if(arr[pos]==prev){
            //shift
            //position = index
            size = shift_array(arr,size,pos);
            //note do not move forward

        }
        else{
            //update prev and pos
            prev = arr[pos];
            pos++;
        }
    }
return size;
}
int shift_array(int arr[], int size, int index){
    //fill in the gap at index
    for(int i=index;i<size-1;i++){
        arr[i] = arr[i+1];
    }
return size-1;
}
