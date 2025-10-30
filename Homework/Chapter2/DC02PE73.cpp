#include "allinclude.h"  //DO NOT edit this line
Status DestroyList_L(LinkList &L) 
{    // Add your code here
    LinkList p;
    while (L) {
        p = L->next;
        free(L);
        L = p;
    }
    return OK;
}