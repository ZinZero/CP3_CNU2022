#include <stdio.h>
#include <string.h>

// 문자열 비교
int main(){
    char s1[10] = "Hello";
    char *s2 = "Hello";

    int ret = strcmp(s1, s2);   //문자열이 같으면 0 

    printf("%d\n", ret);

    return 0;
}