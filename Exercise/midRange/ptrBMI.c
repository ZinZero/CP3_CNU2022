#include <stdio.h>

void BMI(float *p){
    int judge;

    for(int idx = 0; idx < 3; idx++){
        if(*(p + idx) < 20){
            judge = 1;
        }
        else if(*(p + idx) <= 24){
            judge = 2;
        }
        else{
            judge = 0;
        }

        if(judge == 1){
            printf("low ");
        }
        else if(judge == 2){
            printf("normal ");
        }
        else{
            printf("warning ");
        }
    }
    printf("\n");
}

int main(){
    float person[3];

    for(int idx = 0; idx < 3; idx++){
        scanf("%f", &person[idx]);
    }

    BMI(person);


}