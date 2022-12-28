#include <stdio.h>
#include <string.h>

struct student
{
    char name[30];
    char address[30];
};

int main()
{
    struct student s[10];
    char input[30];
    int flag = 0;

    for(int i = 0; i < 10; i++){
        scanf("%s", s[i].name);
        scanf("%s", s[i].address);
    }

    scanf("%s", input);

    for(int i = 0; i < 10; i++){
        int judge = strcmp(input, s[i].name);
        if(judge == 0){
            flag = i;
        }
    }

    printf("%s\n", s[flag].address);

    return 0;
}