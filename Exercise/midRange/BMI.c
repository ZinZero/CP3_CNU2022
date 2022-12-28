#include <stdio.h>

int BMI(float f){
    if(f < 20){
        return 1;
    }
    else if(20 <= f && f <= 24){
        return 2;
    }
    else {
        return 0;
    }
}

int main(){

    int judge;
    float bmi;
    scanf("%f", &bmi);
    judge = BMI(bmi);

    if(judge == 1){
        printf("low \n");
    }
    else if(judge == 2){
        printf("normal \n");
    }
    else{
        printf("warning \n");
    }

    return 0;
}