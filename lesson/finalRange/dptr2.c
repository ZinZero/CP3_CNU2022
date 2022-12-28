#include <stdio.h>

void swap(int **num1, int **num2);

int main(){
    int num1 = 10;
    int num2 = 20;

    int *point_num1 = &num1;
    int *point_num2 = &num2;

    printf("%d %d\n", num1, num2);
    printf("%d %d\n", *point_num1, *point_num2);

    swap(&point_num1, &point_num2); // 싱글 포인터의 주소 값을 넘겨줌

    printf("----swap----\n");
    printf("%d %d\n", num1, num2);
    printf("%d %d\n", *point_num1, *point_num2);
}

void swap(int **num1, int **num2){    // 싱글 포인터의 주소 값을 더블 포인터 매개 변수로 얻어옴
    int *tmp;   // 임시로 사용할 싱글 포인터
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}