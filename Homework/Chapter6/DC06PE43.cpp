#include "allinclude.h"

void CopyBiTree(BiTree T, BiTree &TT) {
    if (T == NULL) {
        TT = NULL;
        return;
    }

    TT = new BiTNode;
    TT->data = T->data;
    CopyBiTree(T->lchild, TT->lchild);
    CopyBiTree(T->rchild, TT->rchild);
}