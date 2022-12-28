#include <stdio.h>

int main(){
    char arr[30];
    char ch;
    int i = 0;

    while((ch = getchar()) != '\n'){
        arr[i] = ch;
        i++;
    }
    i = 0;

    while(arr[i] != '\0'){
        printf("%c", arr[i]);
        i++;
    }

}
