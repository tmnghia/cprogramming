#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

SLL_BOOL cbCompare(void *val1, void *val2)
{
    int v1 = *(int *)val1;
    int v2 = *(int *)val2;

    return v1 == v2 ? SLL_TRUE : SLL_FALSE;
}

void displayList(SLL_NODE *head)
{
    SLL_NODE *pTemp = NULL;

    printf("%s():%d head: %p\n", __FUNCTION__, __LINE__, head);

    if (!head)
        return;

    pTemp = head->pNext;
    while(pTemp)
    {
        printf("%d\n", *(int *)pTemp->data);
        pTemp = pTemp->pNext;
    }
}

int main()
{
    SLL_NODE *intList = NULL;
    int *data1 = NULL;
    int *data2 = NULL;
    int *data3 = NULL;
    SLL_NODE *node1, *node2, *node3;

    data1 = (int *)calloc(1, sizeof(int));
    data2 = (int *)calloc(1, sizeof(int));
    data3 = (int *)calloc(1, sizeof(int));

    node1 = (SLL_NODE *)calloc(1, sizeof(SLL_NODE));
    node2 = (SLL_NODE *)calloc(1, sizeof(SLL_NODE));
    node3 = (SLL_NODE *)calloc(1, sizeof(SLL_NODE));

    *data1 = 1;
    *data2 = 2;
    *data3 = 3;

    intList = sllInit();

    node1->data = data1;
    node2->data = data2;
    node3->data = data3;

    printf("node1: %p %d\n" , node1, *data1);
    printf("node2: %p %d\n" , node2, *data2);
    printf("node3: %p %d\n" , node3, *data3);

    displayList(intList);

    sllInsert(intList, node1);
    displayList(intList);

    sllInsert(intList, node2);
    displayList(intList);

    sllInsert(intList, node3);
    displayList(intList);

    printf("found node1: %p\n", sllFind(intList, data1, cbCompare));
    printf("found node3: %p\n", sllFind(intList, data3, cbCompare));
    printf("found node2: %p\n", sllFind(intList, data2, cbCompare));


    sllRemove(intList, node1, cbCompare);
    displayList(intList);
    sllRemove(intList, node3, cbCompare);
    displayList(intList);

    sllDestroy(&intList);

    displayList(intList);

    return 0;
}

