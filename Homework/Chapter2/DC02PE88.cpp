#include "allinclude.h"  //DO NOT edit this line

Status Cut_L(LinkList L, int i)
{
    if (i < 1) {
        return ERROR;
    }

    LNode *p = L;
    int j = 0;

    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL || p->next == NULL) {
        return ERROR;
    }

    LNode *q = p->next;
    p->next = NULL;

    LNode *r;
    while (q != NULL) {
        r = q->next;
        free(q);
        q = r;
    }

    return OK;
}