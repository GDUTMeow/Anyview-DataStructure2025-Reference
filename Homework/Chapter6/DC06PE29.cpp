#include "allinclude.h"  //DO NOT edit this line
void printNoLessThanKey_PostOrder(BiTree T, TElemType k) {
    if (T == NULL) {
        return;
    }

    printNoLessThanKey_PostOrder(T->lchild, k);
    printNoLessThanKey_PostOrder(T->rchild, k);

    if (T->data >= k) {
        printKey(T->data);
    }
}