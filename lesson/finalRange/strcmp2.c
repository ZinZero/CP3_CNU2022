#include <stdio.h>
#include <string.h>

int main(){
    // aaa -> 97 97 97
    // aab -> 97 97 98
    // aac -> 97 97 99

    printf("%d\n", strcmp("aaa", "aaa")); // 0 : ==
    printf("%d\n", strcmp("aab", "aaa")); // 1 : >
    printf("%d\n", strcmp("aab", "aac")); // -1 : <

    return 0;
}