#include "allinclude.h"

void Degree1(BiTree T, int &count) {
    if (T == NULL) {
        return;
    }

    if ((T->lchild != NULL && T->rchild == NULL) || (T->lchild == NULL && T->rchild != NULL)) {
        count++;
    }

    Degree1(T->lchild, count);
    Degree1(T->rchild, count);
}