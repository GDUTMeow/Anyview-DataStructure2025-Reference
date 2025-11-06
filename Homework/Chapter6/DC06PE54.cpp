#include "allinclude.h"
void ChangeTree(BiTree &T) {
    if (T == NULL) {
        return;
    }

    if (T->lchild == NULL && T->rchild != NULL) {
        T->lchild = T->rchild;
        T->rchild = NULL;
    }

    ChangeTree(T->lchild);
    ChangeTree(T->rchild);
}