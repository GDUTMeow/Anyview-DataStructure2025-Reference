#include "allinclude.h"  //DO NOT edit this line

Status Split_L(LinkList L, LinkList &Li, int i)
{
    if (i < 1) {
        Li = NULL;
        return ERROR;
    }

    LNode *p = L;
    int j = 0;

    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL || p->next == NULL) {
        Li = NULL;
        return ERROR;
    }

    Li = (LinkList)malloc(sizeof(LNode));
    if (Li == NULL) exit(EOVERFLOW);

    Li->next = p->next;
    p->next = NULL;

    return OK;
}