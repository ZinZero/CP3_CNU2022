#include <stdio.h>
void func(int *x, int (*y)[3]){

    for(int idx = 0; idx < 6; idx++){
        printf("%d ", x[idx]);
    }
    printf("\n");

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", y[i][j]);
        }
    }

    printf("\n");
}

void main(){
		int arr1[6] = {10,20,30,40,50,60};
		int arr2[2][3] = {
            {100,200,300},
            {400,500,600}
            };

		func(arr1, arr2);
}