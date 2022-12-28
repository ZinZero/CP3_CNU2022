#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *ptr1 = (int*)malloc(sizeof(int));
    int *ptr2 = (int*)malloc(sizeof(int) * 7);
    int **ptr3 = (int**)malloc(sizeof(int*) * 2);
    int count = 1;

    *ptr1 = 20; // ptr1[0] = 20;

    for(int i = 0; i < 7; i++){
        ptr2[i] = i + 1;
    }

    for(int i = 0; i < 2; i++){
        ptr3[i] = (int*)malloc(sizeof(int) * 3);
        for(int j = 0; j < 3; j++){
            ptr3[i][j] = count;
            count++;
        }
    }

    printf("%d\n", *ptr1);
    printf("%d\n\n", ptr1[0]);
    for(int i = 0; i < 7; i++){
        printf("%d ", ptr2[i]);
    }
    printf("\n\n");

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", ptr3[i][j]);
        }
        printf("\n");
    }

    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}