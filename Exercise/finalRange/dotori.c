#include <stdio.h>
#include <string.h>

struct dotori
{
    int id;
    int visitor;
};

int main()
{
    struct dotori preson[10];

    int input;
    int flag = 0; // true

    for(int i = 0; i < 10; i++){
        preson[i].id = 100 + i;
        preson[i].visitor = 0;
    }

    while(flag == 0){
        scanf("%d", &input);
        if(input > 0){
            for(int i = 0; i < 10; i++){
                int order = preson[i].id;
                if(input == order) {
                    preson[i].visitor += 1;
                }
            }
            
        }else{
            flag = -1; // flase
        }
    }

    for(int i = 0; i < 10; i++){
        printf("%d:%d\n", preson[i].id, preson[i].visitor);
    }

    return 0;
}