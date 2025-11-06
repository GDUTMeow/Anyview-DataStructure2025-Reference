#include "allinclude.h"
Status SmallBiTree(BiTree T) {
    if (T == NULL) {
        return TRUE;
    }

    if (T->lchild) {
        if (T->data >= T->lchild->data) {
            return FALSE;
        }
    }

    if (T->rchild) {
        if (T->data >= T->rchild->data) {
            return FALSE;
        }
    }

    return SmallBiTree(T->lchild) && SmallBiTree(T->rchild);
}