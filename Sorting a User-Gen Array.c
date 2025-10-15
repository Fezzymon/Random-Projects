#include <stdio.h>

int main(){
int N;
printf("Enter N: ");
scanf("%d", &N);
int arr[N];
for(int i=0;i<N;i++){
    printf("Enter #%d: ", i+1);
    scanf("%d", &arr[i]);
}
for(int i=0;i<N-1;i++){
    for(int j=0;j<N-1-i;j++){
    if(arr[j]>arr[j+1]){
    int temp =  arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = temp;
    }
    }
}
printf("\n{");
for(int i=0;i<N;i++){
    printf("%d", arr[i]);
    if(i<N-1){
        printf(",");
    }
}
printf("}");
return 0;
}
