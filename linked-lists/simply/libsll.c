#include <stdlib.h>
#include <stdio.h>

#include "sll.h"

SLL_NODE *sllInit()
{
    SLL_NODE *head = NULL;

    head = (SLL_NODE *)calloc(1, sizeof(SLL_NODE));
    if (!head) {
        return NULL;
    }
    head->pNext = NULL;

    return head;
}

SLL_RET sllInsert(SLL_NODE *head, SLL_NODE *node)
{
    if (!head || !node) {
        return SLL_FAILURE;
    }

    node->pNext = head->pNext;
    head->pNext = node;

    return SLL_SUCCESS;
}

SLL_RET sllRemove(SLL_NODE *head, SLL_NODE *node, SLL_BOOL (*compare)(void *val1, void *val2))
{
    SLL_NODE *pCurrent = NULL;
    SLL_NODE *pPrevious = NULL;
    int ret = -1;
    printf("%s():%d head: %p, node: %p\n", __FUNCTION__, __LINE__, head, node);

    if (!head || !node || !head->pNext) {
        return SLL_FAILURE;
    }

    pCurrent = head->pNext;
    pPrevious = head;
    while (pCurrent != NULL) {
        if (compare(pCurrent->data, node->data) == SLL_TRUE) {
            pPrevious->pNext = pCurrent->pNext;
            free(pCurrent->data);
            free(pCurrent);

            return SLL_SUCCESS;
        }

        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    return SLL_FAILURE;
}

SLL_NODE *sllFind(SLL_NODE *head, void* value, SLL_BOOL (*compare)(void *val1, void *val2))
{
    SLL_NODE *pTemp = NULL;

    if (!head)
        return SLL_SUCCESS;

    pTemp = head->pNext;
    while(pTemp) {
        if (compare(pTemp->data, value) == SLL_TRUE)
            return pTemp;

        pTemp = pTemp->pNext;
    }

    return NULL;
}

SLL_RET sllDestroy(SLL_NODE **head)
{
    SLL_NODE *pCurrent = NULL;
    SLL_NODE *pTemp = NULL;
    printf("%s():%d head: %p *head: %p\n", __FUNCTION__, __LINE__, head, *head);

    if (!head || !*head)
        return SLL_SUCCESS;

    pCurrent = (*head)->pNext;

    while(pCurrent) {
        pTemp = pCurrent;
        pCurrent = pCurrent->pNext;

        free(pTemp->data);
        pTemp->data = NULL;

        free(pTemp);
        pTemp = NULL;
    }

    free(*head);
    *head = NULL;
}
