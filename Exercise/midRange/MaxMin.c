#include <stdio.h>

int main(){
    int max = 0, min = 0;;
    int maxIdx = 1, minIdx = 1;
    int *ptr;
    int *ptr2;
    int arr[9];

    for(int idx = 0; idx < 9; idx++){
        scanf("%d", &arr[idx]);
    }
    ptr = arr;

    max = *ptr;
    min = *ptr;

    for(int idx = 0; idx < 9; idx++){
        if(max < *(ptr + idx)) {
            max = *(ptr + idx);
            maxIdx = idx + 1;
        }
        if(min > *(ptr + idx)){
            min = *(ptr + idx);
            minIdx = idx + 1;
        }
    }

    printf("%d\n", max);
    printf("%d\n", maxIdx);
    printf("%d\n", min);
    printf("%d\n", minIdx);

    return 0;
}