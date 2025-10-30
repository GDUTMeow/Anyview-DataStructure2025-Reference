#include "allinclude.h"  //DO NOT edit this line
Status Insert_L(LinkList L, int i, ElemType e)
{
    if (i < 1) {
        return ERROR;
    }

    LinkList p = L;
    int j = 0;

    while (p && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!p) {
        return ERROR;
    }

    LinkList s = (LinkList)malloc(sizeof(LNode));
    if (!s) {
        return ERROR;
    }
    s->data = e;
    
    s->next = p->next;
    p->next = s;
    
    return OK;
}