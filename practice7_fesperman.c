#include <stdio.h>
#define GRID_SIZE 3
int get_magic_constant(int n);
int is_magic_square(int grid[GRID_SIZE][GRID_SIZE], int size, int target);
int validate_rows(int grid[GRID_SIZE][GRID_SIZE], int size, int target);
int validate_cols(int grid[GRID_SIZE][GRID_SIZE], int size, int target);
int validate_diag1(int grid[GRID_SIZE][GRID_SIZE], int size, int target);
int validate_diag2(int grid[GRID_SIZE][GRID_SIZE], int size, int target);
int main(void){
    //
    int data[GRID_SIZE][GRID_SIZE], T,res;
    printf("Enter the Number of Test Cases: ");
    scanf("%d", &T);
    for(int i=1;i<=T;i++){
        printf("Enter the Grid: ");
        for(int Y=0;Y<GRID_SIZE;Y++){
            for(int X=0;X<GRID_SIZE;X++){
                scanf("%d", &data[Y][X]);
            }
        }
        res = is_magic_square(data, GRID_SIZE, get_magic_constant(GRID_SIZE));
        printf("%d: %s\n",i,res ? "Magic" : "Not Magic");
    }
    //
    return 0;
}
int get_magic_constant(int n){
    int magic_constant = (n*(n*n + 1))/2;
    return magic_constant;
}
int is_magic_square(int grid[GRID_SIZE][GRID_SIZE], int size, int target){
    //satisfies all conditions
    return validate_rows(grid, size, target)
           && validate_cols(grid, size, target)
           && validate_diag1(grid, size, target)
           && validate_diag2(grid, size, target);
}
int validate_rows(int grid[GRID_SIZE][GRID_SIZE], int size, int target){
    int sum;
    for(int i=0; i<size;i++){
        sum = 0; //reset
        for(int j=0;j<size;j++){
            sum = sum + grid[i][j];
        }
        if(sum != target)return 0;
    }
    return 1;
}
int validate_cols(int grid[GRID_SIZE][GRID_SIZE], int size, int target){
    int sum;
    for(int i=0; i<size;i++){
        sum = 0; //reset
        for(int j=0;j<size;j++){
            sum = sum + grid[j][i];
        }
        if(sum != target)return 0;
    }
    return 1;
}
int validate_diag1(int grid[GRID_SIZE][GRID_SIZE], int size, int target){
    //upper left to lower right
    int sum = 0;
    for(int i=0;i<size;i++){
        sum = sum + grid[i][i];
    }
    if(sum != target)return 0;
    return 1;

}
int validate_diag2(int grid[GRID_SIZE][GRID_SIZE], int size, int target){
    //upper right to lower left
    int sum = 0;
    for(int i=size-1;i>=0;i--){
        sum = sum + grid[i][i];

    }
    if(sum != target)return 0;
    return 1;
}
