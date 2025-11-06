#include "allinclude.h"

void DestroySubTree(BiTree &T) {
    if (T == NULL) {
        return;
    }
    DestroySubTree(T->lchild);
    DestroySubTree(T->rchild);
    delete T;
    T = NULL;
}

void ReleaseX(BiTree &bt, char x) {
    if (bt == NULL) {
        return;
    }

    if (bt->data == x) {
        DestroySubTree(bt);
        return;
    }
    
    ReleaseX(bt->lchild, x);
    ReleaseX(bt->rchild, x);
}