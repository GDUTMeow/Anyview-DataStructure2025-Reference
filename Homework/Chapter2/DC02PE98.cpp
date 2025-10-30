#include "allinclude.h"  //DO NOT edit this line

Status isLeagalDuCirLinkList(DuCirLinkList L)
{
    if (L == NULL) {
        return TRUE;
    }

    if (L->next == NULL || L->prior == NULL) {
        return FALSE;
    }

    if (L->next == L) {
        if (L->prior == L) {
            return TRUE;
        } else {
            return FALSE;
        }
    }

    if (L->next->prior != L) {
        return FALSE;
    }
    if (L->prior->next != L) {
        return FALSE;
    }

    DuLNode* p = L->next;
    int count = 0;
    int max_node_count = 50000;

    while (p != L) {
        if (p->next == NULL) {
            return FALSE;
        }

        if (p->next->prior != p) {
            return FALSE;
        }
        
        p = p->next;
        
        count++;
        if (count > max_node_count) {
            return FALSE;
        }
    }

    return TRUE;
}