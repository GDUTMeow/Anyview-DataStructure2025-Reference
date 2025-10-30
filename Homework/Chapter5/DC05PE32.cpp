#include "allinclude.h"  //DO NOT edit this line

Status Equal(GList A, GList B)
{
    if (A == NULL && B == NULL) {
        return TRUE;
    }

    if (A == NULL || B == NULL || A->tag != B->tag) {
        return FALSE;
    }

    if (A->tag == ATOM) {
        return (A->un.atom == B->un.atom);
    } else {
        return Equal(A->un.ptr.hp, B->un.ptr.hp) && Equal(A->un.ptr.tp, B->un.ptr.tp);
    }
}