#include "allinclude.h"  //DO NOT edit this line

void InterleavedTravelDuCirLinkList(DuCirLinkList L, DuLNode* p)
{
    if (L == NULL || L->next == L) {
        return;
    }

    int count = 0;
    DuLNode *counter_node = L->next;
    while (counter_node != L) {
        count++;
        counter_node = counter_node->next;
    }

    if (count == 0) {
        return;
    }

    DuLNode* fwd = p->next;
    DuLNode* bwd = p->prior;
    int i;
    int loop_limit;

    if (p == L) {
        loop_limit = count;
    } else {
        loop_limit = count - 1;
    }

    for (i = 0; i < loop_limit; i++) {
        if (i % 2 == 0) {
            if (fwd == L) {
                fwd = fwd->next;
            }
            printf("%c", fwd->data);
            fwd = fwd->next;
        } else {
            if (bwd == L) {
                bwd = bwd->prior;
            }
            printf("%c", bwd->data);
            bwd = bwd->prior;
        }
    }

    if (p != L) {
        printf("%c", p->data);
    }
}