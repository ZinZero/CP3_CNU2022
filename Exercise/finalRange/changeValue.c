#include <stdio.h>

int main(){
    int len;

    scanf("%d", &len);

    int arr[len];

    for(int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    int *pArr = arr;
    int idx, value;

    scanf("%d %d", &idx, &value);

    pArr[idx] = value;

    for(int i = 0; i < len; i++){
        printf("%d ", pArr[i]);
    }

    printf("\n");

    return 0;

}