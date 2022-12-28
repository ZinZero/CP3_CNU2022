#include <stdio.h>

void func(int (*arr)[3]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
    }

    printf("\n");
}

void main(){
    int iarr[2][3] = {{10,20,30},{100,200,300}};
    func(iarr);
}