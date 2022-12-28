#include <stdio.h>

int main(){

    int input_num, result;

    printf("정수 입력 : ");
    scanf("%d", &input_num);

    result = input_num % 2;

    if(result != 0){
        printf("%d는 홀수입니다. \n", input_num);
    }
    else{
        printf("%d는 짝수입니다. \n",  input_num);
    }

    return 0;
}