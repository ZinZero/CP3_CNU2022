#include <stdio.h>

int Fibo(int n){
    int f1 = 1;
    int f2 = 1;

    if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 1;
    }
    else{
        return Fibo(n -1) + Fibo(n -2);
    }

}

int main(){
    int X, result;

    scanf("%d", &X);

    result = Fibo(X);

    printf("%d \n", result);

    return 0;
}