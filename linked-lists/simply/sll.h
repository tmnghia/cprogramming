#ifndef __SLL_H__
#define __SLL_H__

typedef enum
{
    SLL_SUCCESS,
    SLL_FAILURE
} SLL_RET;

typedef enum
{
    SLL_TRUE,
    SLL_FALSE
} SLL_BOOL;

typedef struct SLL_NODE_S
{
    struct SLL_NODE_S   *pNext;
    void                *data;
} SLL_NODE;

SLL_NODE *sllInit(void);
SLL_RET sllDestroy(SLL_NODE **head);
SLL_RET sllInsert(SLL_NODE *head, SLL_NODE *node);
SLL_RET sllRemove(SLL_NODE *head, SLL_NODE *node, SLL_BOOL (*compare)(void *val1, void *val2));
SLL_NODE *sllFind(SLL_NODE *head, void* value, SLL_BOOL (*compare)(void *val1, void *val2));

#endif /*__SLL_H__*/
