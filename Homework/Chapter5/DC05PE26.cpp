#include "allinclude.h"  //DO NOT edit this line

int GListLength(GList L)
{
    if (L == NULL) {
        return 0;
    }
    
    if (L->tag == ATOM) {
        return 1;
    }

    int count = 0;
    GList p = L;
    while (p != NULL) {
        count++;
        p = p->un.ptr.tp;
    }
    return count;
}