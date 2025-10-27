#include <stdio.h>

void selectionSort(int arr[], int n);
void printArray(int arr[], int size);
void arraySearch(int arr[], int size);
// Main function
int main() {
    int n;
    printf("Enter the Size of the Array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("#%d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    arraySearch(arr, n);
    return 0;
}

// Function to perform selection sort
void selectionSort(int arr[], int size) {
   int min_pos;
   for(int i=0;i<size-1;i++){
       min_pos=i;
       for(int j=i+1;j<size;j++){
           if(arr[i]>arr[j])min_pos=j;
       }
       if(min_pos != i){
           int temp = arr[i];
           arr[i] = arr[min_pos];
           arr[min_pos] = temp;
       }
   }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void arraySearch(int arr[], int size){
    int search;
    printf("What number are you searching for: ");
    scanf("%d",&search);
    for(int i=0;i<size;i++){
        if(arr[i]==search){
            printf("%d is located at Array[%d]",search,i);
            break;
        }
        if(i==size-1)printf("Your search was not found...");
    }
}



