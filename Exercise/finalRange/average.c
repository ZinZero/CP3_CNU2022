#include <stdio.h>

int main(){

    int x, y;

    scanf("%d %d", &x, &y);

    int arr[x][y];

    for(int i = 0; i < x; i++){
        for(int j = 0 ; j < y; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0, average = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0 ; j < y; j++){
            sum += arr[i][j];
        }
    }

    average = sum / (x * y);
    printf("%d \n", (int)average);
    
    return 0;
}