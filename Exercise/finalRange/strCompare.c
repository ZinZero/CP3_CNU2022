#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char s1[20];
    char s2[20];

    scanf("%s %s", s1, s2);

    int result = strcmp(s1, s2);

    if(result == 0){
        printf("%d\n", 1);
    }
    else{
        printf("%d\n", 0);
    }

    return 0;
}