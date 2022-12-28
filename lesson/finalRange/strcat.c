#include <stdio.h>
#include <string.h>

// 문자열 붙이기

int main(){
    char s1[10] = "World";
    char s2[10] = "Hello";

    strcat(s2, s1); // s2 + s1

    printf("%s\n", s2);

    return 0;
}