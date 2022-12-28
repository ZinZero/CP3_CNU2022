#include <stdio.h>
#define ARRAY_SIZE 5

int foo(int arr[][ARRAY_SIZE], int len){
    int result = 0;
    int min = 0;
    for(int i = 0; i < len; i++){
        min = arr[i][0];
        for(int j = 0; j < ARRAY_SIZE; j ++){
            if(min > arr[i][j]){
                min = arr[i][j];
            }
        }
        result += min;
    }

    return result;
}

int main() {
    int x;
    scanf("%d", &x);
    int arr[x][ARRAY_SIZE];

    for(int i = 0; i < x; i++){
        for(int j = 0; j < ARRAY_SIZE; j++){
            scanf("%d", &arr[i][j]);
        }
    }    
    
    int result = foo(arr, x);
    printf("%d\n",result);
    
    return 0;
}