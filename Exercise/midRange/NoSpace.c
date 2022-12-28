#include <stdio.h>

int main(){
    int n;
    int sum = 0, idx = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char str[80];
        scanf("%s", str);
        while(str[idx] != '\0'){
            idx++;
        }
        sum = sum + idx;
        idx = 0;
    }

    printf("%d\n", sum);

    return 0;
}
