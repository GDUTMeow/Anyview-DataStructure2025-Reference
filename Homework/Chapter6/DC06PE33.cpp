#include "allinclude.h"  //DO NOT edit this line
void ExchangeSubTree(BiTree &T) {
    if (T == NULL) {
        return;
    }

    ExchangeSubTree(T->lchild);
    ExchangeSubTree(T->rchild);

    BiTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
}