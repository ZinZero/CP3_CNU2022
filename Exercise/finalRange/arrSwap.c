#include <stdio.h>

void swap(int *p, int *q){
    for(int i = 0; i < 5; i++){
        int temp = *(p + i);
        *(p + i) = *(q + i);
        *(q + i) = temp;
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", *(p + i));
    }

    printf("\n");

    for(int i = 0; i < 5; i++){
        printf("%d ", *(q + i));
    }

    printf("\n");

}

int main(){
    int arr1[5] = {0, 0, 0, 0, 0};
    int arr2[5] = {0, 0, 0, 0, 0};

    for(int i = 0; i < 5; i++){
        scanf("%d", &arr1[i]);
    }
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr2[i]);
    }

    swap(arr1, arr2);
}