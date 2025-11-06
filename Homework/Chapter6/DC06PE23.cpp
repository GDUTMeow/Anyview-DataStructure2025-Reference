#include "allinclude.h"  //DO NOT edit this line
void printNoLessThanKey_InOrder(BiTree T, TElemType k) {
    if (T == NULL) {
        return;
    }

    printNoLessThanKey_InOrder(T->lchild, k);

    if (T->data >= k) {
        printKey(T->data);
    }
    
    printNoLessThanKey_InOrder(T->rchild, k);
}