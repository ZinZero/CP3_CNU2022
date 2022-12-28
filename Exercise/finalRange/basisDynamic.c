#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int** arr;
    int x, y;
    int count = 1;

    scanf("%d %d", &x, &y);

    arr = (int**)malloc(sizeof(int*) * y);

    for(int i = 0; i < y; i++){
        arr[i] = (int*)malloc(sizeof(int) * x);
        for(int j = 0; j < x; j++){
            arr[i][j] = count;
            count++;
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