#include "allinclude.h"  //DO NOT edit this line

Status Delete_L(LinkList L, int i, ElemType &e)
{
    LNode *p = L;
    int j = 0;

    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!p->next || i < 1) {
        return ERROR;
    }

    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);

    return OK;
}