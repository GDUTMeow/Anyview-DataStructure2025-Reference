#include "allinclude.h"
Status BTEqual(BiTree T1, BiTree T2) {
    if (T1 == NULL && T2 == NULL) {
        return TRUE;
    }

    if (T1 == NULL || T2 == NULL || T1->data != T2->data) {
        return FALSE;
    }

    return BTEqual(T1->lchild, T2->lchild) && BTEqual(T1->rchild, T2->rchild);
}