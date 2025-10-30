#include "allinclude.h"  //DO NOT edit this line

Status DeleteSome_L(LinkList L, ElemType x)
{
    if (L == NULL || L->next == NULL) {
        return 0;
    }

    LNode *p = L;
    LNode *q = L->next;
    LNode *temp;
    int count = 0;

    while (q != NULL) {
        if (q->data < x) {
            temp = q;
            p->next = q->next;
            q = q->next;
            free(temp);
            count++;
        } else {
            p = q;
            q = q->next;
        }
    }
    return count;
}