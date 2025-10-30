#include "allinclude.h"  //DO NOT edit this line
Status ClearList_L(LinkList &L)
{    // Add your code here
    if (!L) {
        return ERROR;
    }

    LinkList p = L->next;
    LinkList q;

    while (p) {
        q = p->next;
        free(p);
        p = q;
    }

    L->next = NULL;
    return OK;
}