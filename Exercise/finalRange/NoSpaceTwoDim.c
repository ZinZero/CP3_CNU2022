#include <stdio.h>

int main(){
    int n;
    int sum = 0, idx = 0;

    scanf("%d", &n);

    char str[n][100];

    for(int i = 0; i < n; i++){
        scanf("%s", str[i]);
        while(str[i][idx] != '\0'){
            idx++;
        }
        sum = sum + idx;
        idx = 0;
    }

    printf("%d\n", sum);

    return 0;
}