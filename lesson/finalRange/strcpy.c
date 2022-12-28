#include <stdio.h>
#include <string.h>

// 문자열 복사
int main(){
    char s1[10] = "Hello";
    char s2[10];

    strcpy(s2, s1);

    printf("%s\n", s2);

    return 0;
}