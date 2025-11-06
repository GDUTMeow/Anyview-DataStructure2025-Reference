#include "allinclude.h"
Status isIsomorphic(BiTree T1, BiTree T2) {
    if (T1 == NULL && T2 == NULL) {
        return TRUE;
    }

    if (T1 == NULL || T2 == NULL) {
        return FALSE;
    }

    if (T1->data != T2->data) {
        return FALSE;
    }

    return (isIsomorphic(T1->lchild, T2->lchild) && isIsomorphic(T1->rchild, T2->rchild)) ||
           (isIsomorphic(T1->lchild, T2->rchild) && isIsomorphic(T1->rchild, T2->lchild));
}