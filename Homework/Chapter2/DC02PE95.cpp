#include "allinclude.h"  //DO NOT edit this line

void reverseDuCirLinkList(DuCirLinkList L)
{
    if (L == NULL || L->next == L) {
        return;
    }

    DuLNode *p = L;
    DuLNode *temp;

    do {
        temp = p->next;
        p->next = p->prior;
        p->prior = temp;
        p = p->prior;
    } while (p != L);
}