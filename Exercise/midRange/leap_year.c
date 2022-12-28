#include <stdio.h>

int main(){

    int y;
    int process1, process2, process3;

    scanf("%d", &y);

    process1 = y % 4;
    process2 = y % 100;
    process3 = y % 400;

    if(process1 == 0){
        if(process2 != 0 || process3 == 0){
            printf("YES \n");
        }
        else{
            printf("NO \n");
        }
    }
    else{
        printf("NO \n");
    }
    
    return 0;
}