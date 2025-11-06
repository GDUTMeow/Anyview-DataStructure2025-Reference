#include "allinclude.h"  //DO NOT edit this line
Status isBrother(BiTree T, TElemType dx, TElemType dy) {
    if (T == NULL) {
        return FALSE;
    }

    if (T->lchild && T->rchild) {
        if ((T->lchild->data == dx && T->rchild->data == dy) ||
            (T->lchild->data == dy && T->rchild->data == dx)) {
            return TRUE;
        }
    }

    return isBrother(T->lchild, dx, dy) || isBrother(T->rchild, dx, dy);
}