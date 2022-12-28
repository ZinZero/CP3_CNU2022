#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int** arr;
    int x, y;
    int average = 0;

    scanf("%d %d", &x, &y);

    arr = (int**)malloc(sizeof(int*) * y);

    for(int i = 0; i < y; i++){
        arr[i] = (int*)malloc(sizeof(int) * x);
        for(int j = 0; j < x; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            sum += arr[i][j];
        }
    }

    average = (int) (sum / (x * y));

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(average >= arr[i][j]){
                arr[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}