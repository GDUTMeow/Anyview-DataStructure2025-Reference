#include "allinclude.h"  //DO NOT edit this line

void reverseDuLinkList(DuLinkList L)
{
    // If the list is empty or has only one element, no reversal is needed.
    if (L == NULL || L->next == NULL || L->next->next == NULL) {
        return;
    }

    DuLNode *p = L->next; // p points to the first node of the original list.
    L->next = NULL;       // Disconnect the list from the header. L now represents the head of the new reversed list.

    while (p != NULL) {
        DuLNode *q = p;      // q is the current node to be moved.
        p = p->next;         // Move p to the next node in the original list.

        // Insert q at the front of the reversed list (immediately after the header L).
        q->next = L->next;
        if (L->next != NULL) {
            L->next->prior = q;
        }
        L->next = q;
        q->prior = L;
    }
}