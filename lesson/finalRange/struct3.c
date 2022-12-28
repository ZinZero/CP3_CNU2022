#include <stdio.h>

typedef struct Date
{
    int deposit;
    int payment;
    int balance;
} Account;

int main()
{
    Account acc;

    acc.deposit = 10000;
    acc.payment = 5000;
    acc.balance = acc.deposit - acc.payment;

    printf("예금 : %d\n", acc.deposit);
    printf("출금 : %d\n", acc.payment);
    printf("잔액 : %d\n", acc.balance);

    return 0;
}