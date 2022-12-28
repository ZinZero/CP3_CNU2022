#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ADD 1
#define DELETE 2
#define FIND 3
#define PRINTALL 4
#define QUIT 5

#define NAMEMAX 10
#define PHONEMAX 15

typedef struct Address // data
{
    char name[NAMEMAX];
    char phone[PHONEMAX];
} Address;

typedef struct AddressBlock
{
    unsigned size;
    Address *book;
    struct AddressBlock *next;
} AddressBlock;

typedef struct AddressBook
{
    unsigned size;
    AddressBlock *head;
} AddressBook;

void initializeAddressBook(AddressBook *addrbook)
{ // AddressBook 생성자
    addrbook->size = 0;
    addrbook->head = NULL;
}

void finalizeAddressBook(AddressBook *addrbook)
{ // AddressBook 소멸자
    AddressBlock *block = addrbook->head;
    while (addrbook->head != NULL)
    {
        while (block->next != NULL)
        {
            block = block->next;
        }
        free(block->book);
        free(block);
    }
}

// function : You should complete the function
Address *findAddressByName(char *name, AddressBook *addrbook)
{ // 이름으로 AddresBook 탐색
    AddressBlock *current = addrbook->head;
    while (current != NULL)
    {
        for (int idx = 0; idx < current->size; idx++)
        {
            if (strcmp(current->book[idx].name, name) == 0)
            {
                return &(current->book[idx]);
            }
        }
        current = current->next;
    }
    return NULL;
}

// function : You should complete the function
AddressBlock *findMergingTarget(AddressBook *addrbook, AddressBlock *source)
{ // 삭제 시 병합할 AddressBook 탐색 및 공간 확보 병합 아님
    AddressBlock *current = addrbook->head;
    while (current != NULL)
    {
        if (current->size < 5)
        {
            if (current != source)
            {
                return current;
            }
        }
        current = current->next;
    }
    return NULL;
}

// function : You should complete the function
int addAddress_first(Address *addr, AddressBook *addrbook)
{ // AddressBook 삽입 및 공간 확보
    char addName[NAMEMAX];
    strcpy(addName, addr->name);
    if (findAddressByName(addName, addrbook) != NULL)
    {
        return FALSE;
    }

    if (addrbook->head == NULL)
    {
        AddressBlock *block = (AddressBlock *)malloc(sizeof(AddressBlock));
        block->size = 0;
        block->next = addrbook->head;
        block->book = (Address *)malloc(sizeof(Address) * 5);
        block->book[0] = *addr;
        addrbook->head = block;
        addrbook->size++;
        addrbook->head->size++;

        return TRUE;
    }

    if (addrbook->head->size < 10 && addrbook->head->size != 5)
    {
        int blockSize = addrbook->head->size;
        addrbook->head->book[blockSize] = *addr;
        addrbook->head->size++;
        addrbook->size++;
    }
    else if (addrbook->head->size == 5)
    {
        Address *exBook = addrbook->head->book;
        addrbook->head->book = (Address *)realloc(exBook, sizeof(Address) * 10);
        addrbook->head->book[5] = *addr;
        addrbook->head->size++;
        addrbook->size++;
    }
    else
    {
        AddressBlock *block2 = (AddressBlock *)malloc(sizeof(AddressBlock));
        block2->next = addrbook->head;
        addrbook->head = block2;
        addrbook->size++;
        addrbook->head->book = (Address *)malloc(sizeof(Address) * 5);
        addrbook->head->book[0] = *addr;
        addrbook->head->size++;
    }

    return TRUE;
}

// function : You should complete the function
int deleteAddressByName(char *name, AddressBook *addrbook)
{ // AddressBook 삭제 및 병합
    if (findAddressByName(name, addrbook) == NULL)
    {
        return FALSE;
    }

    for (AddressBlock *current = addrbook->head; current != NULL; current = current->next)
    {
        char n[NAMEMAX];
        for (int idx = 0; idx < current->size; idx++)
        {

            if (strcmp(current->book[idx].name, name) == 0)
            {
                if (current->size == 1)
                {
                    if (current->next == NULL && current == addrbook->head)
                    {
                        addrbook->head = NULL;
                        free(current->book);
                        free(current);
                    }
                    else if (current == addrbook->head)
                    {
                        addrbook->head = addrbook->head->next;
                        addrbook->head = NULL;
                        free(current->book);
                        free(current);
                    }
                    else if (current->next == NULL)
                    {
                    }
                    else
                    {
                        AddressBlock *tempBlock = addrbook->head;
                        while (tempBlock != NULL)
                        {
                            if (tempBlock->next == current)
                            {
                                tempBlock->next = tempBlock->next->next;
                                free(tempBlock->next->book);
                                free(tempBlock->next);
                                addrbook->size = addrbook->size - 1;
                                break;
                            }
                            tempBlock = tempBlock->next;
                        }
                    }
                    addrbook->size = addrbook->size - 1;
                    return TRUE;
                }
                else
                {
                    strcpy(n, current->book[idx].name);
                    for (int j = idx; j < current->size - 1; j++)
                    {
                        current->book[j] = current->book[j + 1];
                    }
                    current->size = current->size - 1;
                    addrbook->size = addrbook->size - 1;
                }

                // 병합
                if (current->size < 5)
                {
                    AddressBlock *findBlock = findMergingTarget(addrbook, current);
                    if (findBlock != NULL)
                    {
                        AddressBlock *newBlock = (AddressBlock *)malloc(sizeof(AddressBlock));
                        newBlock->book = (Address *)malloc(sizeof(Address) * 10);
                        newBlock->size = findBlock->size + current->size;
                        newBlock->next = NULL;
                        for (int i = 0; i < current->size; i++)
                        {
                            newBlock->book[i] = current->book[i];
                        }
                        for (int i = current->size; i < current->size + findBlock->size; i++)
                        {
                            newBlock->book[i] = findBlock->book[i - current->size];
                        }

                        if (findBlock->next == NULL && addrbook->head)
                        {
                            addrbook->head = NULL;
                            free(findBlock->book);
                            free(findBlock);
                        }
                        else if (findBlock == addrbook->head)
                        {
                            addrbook->head = addrbook->head->next;
                            addrbook->head = NULL;
                            free(findBlock->book);
                            free(findBlock);
                        }
                        else if (findBlock->next == NULL)
                        {
                        }
                        else
                        {
                            AddressBlock *tempBlock = addrbook->head;
                            while (tempBlock->next != NULL)
                            {
                                if (tempBlock->next == findBlock)
                                {
                                    tempBlock->next = tempBlock->next->next;
                                    free(tempBlock->next->book);
                                    free(tempBlock->next);
                                    addrbook->size = addrbook->size - 1;
                                    break;
                                }
                                tempBlock = tempBlock->next;
                            }
                        }

                        if (current->next == NULL && current == addrbook->head)
                        {
                            addrbook->head = NULL;
                            free(current->book);
                            free(current);
                        }
                        else if (current == addrbook->head)
                        {
                            addrbook->head = addrbook->head->next;
                            addrbook->head = NULL;
                            free(current->book);
                            free(current);
                        }
                        else if (current->next == NULL)
                        {
                        }
                        else
                        {
                            AddressBlock *tempBlock = addrbook->head;
                            while (tempBlock != NULL)
                            {
                                if (tempBlock->next == current)
                                {
                                    tempBlock->next = tempBlock->next->next;
                                    free(tempBlock->next->book);
                                    free(tempBlock->next);
                                    addrbook->size = addrbook->size - 1;
                                    break;
                                }
                                tempBlock = tempBlock->next;
                            }
                        }

                        newBlock->next = addrbook->head;
                        addrbook->head = newBlock;
                        newBlock->next = NULL;
                    }
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

int main_menu()
{
    int menu = 0;
    do
    {
        printf("1. Add an address\n");
        printf("2. Delete an address\n");
        printf("3. Find an address\n");
        printf("4. Print all\n");
        printf("5. Quit\n");
        printf("Select: ");

        scanf("%d", &menu);
    } while (menu < 1 || menu > 5);

    return menu;
}

void name_menu(char *name)
{
    printf("Type a name: ");
    scanf("%s", name);
}

void add_menu(Address *addr)
{
    printf("Type a name: ");
    scanf("%s", addr->name);
    printf("Type a phone number: ");
    scanf("%s", addr->phone);
}

// function : You should complete the function
// The code below does not print the appropriate results
int main()
{
    int menu = 0;
    AddressBook addrbook;
    Address addr;
    char name[10];

    initializeAddressBook(&addrbook);
    do
    {
        menu = main_menu();
        printf("\n");

        switch (menu)
        {
        case ADD:
            add_menu(&addr);
            if (addAddress_first(&addr, &addrbook))
                printf("%s is added successfully!\n", addr.name);
            else
                printf("%s already exists in the book\n", addr.name);
            break;
        case DELETE:
            name_menu(name);
            if (deleteAddressByName(name, &addrbook))
                printf("%s is deleted\n", name);
            else
                printf("%s does not exist in the book\n", name);
            break;
        case FIND:
            printf("Type a name: ");
            scanf("%s", name);
            {
                Address *p = findAddressByName(name, &addrbook);
                if (p == NULL)
                    printf("%s is not found\n", name);
                else
                    printf("%s: %s\n", p->name, p->phone);
                break;
            }
        case PRINTALL:
            for (AddressBlock *p = addrbook.head; p != NULL; p = p->next)
            {
                for (int i = 0; i < p->size; i++)
                {
                    printf("%s: %s\n", p->book[i].name, p->book[i].phone);
                }
            }
            break;
        }

        if (menu != QUIT)
        {
            printf("\n");
            printf("---------------------------Providing My AddressBook---------------------------------------\n");

            printf("(Address Book Size: %d)\n\n", addrbook.size);

            for (AddressBlock *p = addrbook.head; p != NULL; p = p->next)
                printf("block size : %d\n", p->size);

            printf("------------------------------------------------------------------------------------------\n");
            printf("\n");
        }

    } while (menu != QUIT);

    finalizeAddressBook(&addrbook);

    return 0;
}