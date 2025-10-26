#include <stdio.h>
#define MAX_COUNT 10

/*
    COP3223C Fall 2025
    Programming Assignment 3
    Student Name: Daniel Fesperman
    File Name: pa3_fesperman.c
    NOTE: I hereby certify that this submission is my original work.
    It was completed independently by me without unauthorized assistance.
    I affirm that all sources consulted have been properly acknowledged.
    No part of this work was copied or plagiarized from any other source/s.
*/

// Note: DO NOT modify or remove TODO comments as it will interfere
// with the grading system. You are not allowed to define any
// other helper functions or to modify other parts of the code. You are
// limited to adding only codes in between the TODO comments.

//Function Prototypes
int compute_secret(int arr[], int size);
int get_mode(int arr[], int size);
int count_unique(int arr[], int size);
int get_min(int arr[], int size);
int get_max(int arr[], int size);
int get_range(int arr[], int size);

int main(void) {
    int T;
    int nums[MAX_COUNT];

    // Determine the number of test cases
    scanf("%d", &T);

    // For each test case
    for(int i = 1; i <= T; i++) {
        // Read 10 numbers and store them in the array
        for(int j = 0; j < MAX_COUNT; j++)
            scanf("%d", &nums[j]);

        // Print the secret code for the test case
        printf("%d: %d\n", i, compute_secret(nums, MAX_COUNT));
    }

    return 0;
}

// Function Definitions
int compute_secret(int arr[], int size) {
    // Compute the secret code based on the statistics
    return get_mode(arr, size) + count_unique(arr, size) +
        get_min(arr, size) + get_max(arr, size) + get_range(arr, size);
}

int get_mode(int arr[], int size) {
    // TODO 1 BEGIN
    int max_count = 0;
    int mode = arr[0];
    for (int i = 0; i < size; i++) {
        int count = 0;//sets count base to 0 so there is no holdover from past variable testing
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;//increases "amount of times this variable has showed up" counter
            }
        }//sets the new mode if current variable shows up more often than previous mode
        if (count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }
    return mode;
    // TODO 1 END
}

int count_unique(int arr[], int size) {
    // TODO 2 BEGIN
    int unq = 0;
    for (int i = 0; i < size; i++) {
        int is_unique = 1; //begins with assumption value is unique then checks to break
        for (int j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                is_unique = 0; // breaks to check next value if not unique
                break;
            }
        }
        if(is_unique){
            unq++;//increase number of unique variables if current is found to be unique
        }
    }
    return unq;
    // TODO 2 END
}

int get_min(int arr[], int size) {
    // TODO 3 BEGIN
    int min = arr[0];//sets a variable to test against from the start
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
    // TODO 3 END
}

int get_max(int arr[], int size) {
    // TODO 4 BEGIN
    int max = arr[0];//sets a variable to test against from the start
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
    // TODO 4 END
}

int get_range(int arr[], int size) {
    // TODO 5 BEGIN
    //bring in the min and max from other funcs then subtract smallest from largest to get range
    int min = get_min(arr, size);
    int max = get_max(arr, size);
    return max - min;
    // TODO 5 END
}
