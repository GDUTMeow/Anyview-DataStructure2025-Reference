#include "allinclude.h"  //DO NOT edit this line
void OrderOut(BSTree T, KeyType k, void(*visit)(TElemType)) {
    if (T == NULL) {
        return;
    }

    if (T->data.key < k) {
        OrderOut(T->rchild, k, visit);
    } else {
        OrderOut(T->rchild, k, visit);
        visit(T->data);
        OrderOut(T->lchild, k, visit);
    }
}