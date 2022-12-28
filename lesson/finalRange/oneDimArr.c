#include <stdio.h>

int main(){
    int arr[5];
    int sum = 0, i;

    arr[0] = 10, arr[1] = 15, arr[2] = 20, arr[3] = 25, arr[4] = 30;

    printf("배열 출력 : ");
    for(i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(i = 0; i < 5; i++){
        sum += arr[i];
    }
    printf("배열요소에 저장된 값의 합 : %d\n", sum);

    return 0;
}