#include <stdio.h>
#define MAX_SIZE 52//+2 because the border ends(50 main width, 52 with ends)

void reset_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C);
void print_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C);
void draw_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C, int x, int y, char s);

int main(void){
    char grid[MAX_SIZE][MAX_SIZE];
    FILE *ifile = NULL;
    //Open the file
    ifile = fopen("data.txt", "r");
    //Check for file error
    if(!ifile){
    //failed
    printf("Error opening file.\n");
    return -1;
    }
    //Read dimensions of canvas
    int row, col;
    fscanf(ifile,"%d%d",&row,&col);
    //Compute dimensions with borders
    row = row+2;
    col = col+2;
    //Reset canvas
    reset_art(grid, row, col);
    int x, y;
    char s;
    //As long as there are still characters to scan
    while(fscanf(ifile, "%d%d %c", &x,&y,&s)!=EOF){
        //draw art
        draw_art(grid,row,col,x,y,s);
    }
    //close file
    fclose(ifile);
    //print artwork
    print_art(grid, row, col);

return 0;
}

void reset_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C){
    //R, C are actual dimensions of border
    for(int i=0; i<R;i++){
        for(int j=0; j<C;j++){
            //First and last rows, do a full border
            if(i==0||i==R-1){
                canvas[i][j] = '*';
            }

            else if(j==0||j==C-1){
                canvas[i][j] = '*';
            }
            else{
                canvas[i][j]= ' ';
            }
        }
    }
}
void print_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C){
     for(int i=0; i<R;i++){
        for(int j=0; j<C;j++){
            printf("%c", canvas[i][j]);
        }
        //move to the next row
        printf("\n");
     }
}

void draw_art(char canvas[MAX_SIZE][MAX_SIZE], int R, int C, int x, int y, char s){
    canvas[x][y] = s;
}
