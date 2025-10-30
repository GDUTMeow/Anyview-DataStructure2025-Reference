#include "allinclude.h"  //DO NOT edit this line

DuLinkList delDuplicateDuLNodes(DuLinkList L)
{
    if (L == NULL || L->next == NULL) {
        return L;
    }

    DuLNode *p = L->next;
    DuLNode *q;
    DuLNode *temp;

    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (q->data == p->data) {
                temp = q;
                q->prior->next = q->next;
                if (q->next != NULL) {
                    q->next->prior = q->prior;
                }
                q = q->next;
                free(temp);
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }
    return L;
}