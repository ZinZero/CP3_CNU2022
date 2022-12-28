#include <stdio.h>

int main(){
    int n, i, j;
    int sum = 0;

    scanf("%d", &n);

    int arr[n];

    for(int idx = 0; idx < n; idx++){
        scanf("%d ", &arr[idx]);
    }

    scanf("%d %d", &i, &j);

    for(int x = i; x <= j; x++){
        sum += arr[x];
    }

    printf("%d\n", sum);

    return 0;

}