#include <stdio.h>

void MinMax(int *arr,int **minPtr, int **maxPtr){
    int *min = 0;
    int *max = 0;

    min = arr;
    max = arr;

    for(int i = 0; i < 5; i++){
        if(*min > arr[i]){
            min = &arr[i];
        }
        if(*max < arr[i]){
            max = &arr[i];
        }
    }

    *minPtr = min;
    *maxPtr = max;
}
int main(){
    int arr[5];
    int *minPtr = 0;
    int *maxPtr = 0;

    for(int idx = 0; idx < 5; idx++){
        scanf("%d", &arr[idx]);
    }

    MinMax(arr, &minPtr, &maxPtr);

    printf("%d %d\n", *minPtr, *maxPtr);
}