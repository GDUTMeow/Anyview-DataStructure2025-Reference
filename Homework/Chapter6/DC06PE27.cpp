#include "allinclude.h"  //DO NOT edit this line
void printNoLessThanKey_PreOrder(BiTree T, TElemType k) {
    if (T == NULL) {
        return;
    }

    if (T->data >= k) {
        printKey(T->data);
    }

    printNoLessThanKey_PreOrder(T->lchild, k);
    printNoLessThanKey_PreOrder(T->rchild, k);
}