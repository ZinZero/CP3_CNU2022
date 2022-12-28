#include <stdio.h>

void sum(int *p, int *q){
    int sum = 0;

    for(int idx = 0; idx < 5; idx++){
        sum += *(p + idx) + *q;
    }

    printf("%d \n", sum);
}

int main(){
    int arr[5];
    int add;

    for(int idx = 0; idx < sizeof(arr) / sizeof(int); idx++){
        scanf("%d", &arr[idx]);
    }

    scanf("%d", &add);
    sum(arr, &add);

}