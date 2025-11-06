#include "allinclude.h"
Status RegularBiTree(BiTree T) {
    if (T == NULL) {
        return TRUE;
    }

    if ((T->lchild == NULL && T->rchild != NULL) || (T->lchild != NULL && T->rchild == NULL)) {
        return FALSE;
    }

    return RegularBiTree(T->lchild) && RegularBiTree(T->rchild);
}