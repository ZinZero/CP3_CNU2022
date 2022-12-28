#include <stdio.h>

int main(){

    int input_num;

    printf("정수 입력 : ");
    scanf("%d", &input_num);

    if(input_num > 0){
        printf("입력한 정수는 %d는 양의 정수 입니다. \n", input_num);
        printf("조건문은 참입니다. \n");
    }

    return 0;
}