#include "allinclude.h"
int BranchNodes(BiTree T) {
    if (T == NULL) {
        return 0;
    }

    if (T->lchild == NULL && T->rchild == NULL) {
        return 0;
    }

    return 1 + BranchNodes(T->lchild) + BranchNodes(T->rchild);
}