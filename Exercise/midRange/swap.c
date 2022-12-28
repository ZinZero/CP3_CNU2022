#include <stdio.h>

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
    printf("%d %d \n", *p, *q);
}

int main(){
    int x, y;

    scanf("%d %d", &x, &y);
    swap(&x, &y);

}