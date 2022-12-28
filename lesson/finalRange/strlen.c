#include <stdio.h>
#include <string.h>

// 문자열 길이

int main(){
    char *s1 = "Hello";
    char s2[10] = "Hello";
    char s3[20] = "Hello World!";

    printf("s1 : %d\n", strlen(s1));
    printf("s2 : %d\n", strlen(s2));
    printf("s3 : %d\n", strlen(s3));

    return 0;
}