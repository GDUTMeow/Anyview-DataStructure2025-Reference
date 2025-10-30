#include "allinclude.h"  //DO NOT edit this line

void OutAtom(GList A, int layer, void(*Out2)(char, int))
{
    if (A == NULL) {
        return;
    }

    if (A->tag == ATOM) {
        Out2(A->un.atom, layer);
    } else { // A->tag == LIST
        OutAtom(A->un.ptr.hp, layer + 1, Out2);
        OutAtom(A->un.ptr.tp, layer, Out2);
    }
}