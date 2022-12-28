#include <stdio.h>

struct Person
{
    char name[20];
    int age;
    char address[100];
};

int main()
{
    struct Person p1;
    struct Person *ptr; // 구조체 포인터 선언


    ptr = &p1;  //p1의 메모리 주소를 구하여 ptr에 할당

    // 화살표를 연산자로 구조체 멤버에 접근하여 값 할당
    ptr->age = 30;

    printf("나이 : %d\n", p1.age);
    printf("나이 : %d\n", ptr->age);

    return 0;
}