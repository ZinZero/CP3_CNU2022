#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5

int foo(int (**arr), int x){
    int result = 0;
    int *min = 0;
    for(int i = 0; i < x; i++){
        min = &arr[i][0];
        for(int j = 0; j < ARRAY_SIZE; j++){
            if(*min > arr[i][j]){
                min = &arr[i][j];
            }
        }
        result += *min;
    }

    return result;
}

int main() {
    int** arr;
    int x;
    int result;
    
    scanf("%d", &x);
    
    arr = (int**)malloc(sizeof(int*) * x);
    for(int i = 0; i < x; i++){
        arr[i] = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < ARRAY_SIZE; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    result = foo(arr, x);
    printf("%d\n", result);
    
    free(arr);
    
    return 0;
}