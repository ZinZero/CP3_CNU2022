#include <stdio.h>

int main(){
    int add;
    int sum = 0;

    int arr[5];
    int *ptr;
    for(int idx = 0; idx < sizeof(arr) /sizeof(int); idx++){
        scanf("%d ", &arr[idx]);
    }

    ptr = arr;

    scanf("%d", &add);

    for(int idx = 0; idx < sizeof(arr) / sizeof(int); idx++){
        ptr[idx] += add;
        sum += ptr[idx];
    }

    printf("%d\n", sum);

    return 0;
}