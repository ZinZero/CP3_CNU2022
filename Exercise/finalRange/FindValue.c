#include <stdio.h>

int main(){
    int x, y, find;
    int findRow = 0, findCol = 0;

    scanf("%d %d", &x, &y);
    scanf("%d", &find);

    int arr[y][x];

    for(int i = 0 ; i < y; i++){
        for(int j = 0 ; j < x; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0 ; i < y; i++){
        for(int j = 0 ; j < x; j++){
            if(arr[i][j] == find){
                findRow = i;
                findCol = j;
            }
        }
    }

    printf("%d %d\n", findRow, findCol);
    return 0;
}