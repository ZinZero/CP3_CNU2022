#include <stdio.h>

int main() {

    int i = 1;

    while (i < 5)
    {
        printf("현재 i의 값은 %d 입니다. \n", i);

        i++;
    }

    printf("while문 종료 후 i의 값은 %d 입니다. \n", i);

    return 0;
    
}
