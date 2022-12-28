#include <stdio.h>

struct date
{
    int month;
    int day;
    int year;
};

struct student
{
    int number;
    char name[20];
    double grade;
    struct date *a;
};

int main(void)
{
    struct date d = {3, 20, 1980};
    struct student s = {20070001, "Kim", 4.3};

    s.a = &d;

    printf("학번 : %d\n", s.number);
    printf("이름 : %s\n", s.name);
    printf("학점 : %f\n", s.grade);
    printf("생년월일 : %d년 %d월 %d일\n\n", s.a->year, s.a->month, s.a->day);

    return 0;
}