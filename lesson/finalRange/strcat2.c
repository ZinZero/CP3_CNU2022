#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *s1 = "World";
    char *s2 = malloc(sizeof(char) * 20);

    strcpy(s2, "Hello");

    strcat(s2, s1);

    printf("%s\n", s2);

    free(s2);

    return 0;
}