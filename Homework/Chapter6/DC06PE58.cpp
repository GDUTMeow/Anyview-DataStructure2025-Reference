#include "allinclude.h"
int countNodes(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    return 1 + countNodes(T->lchild) + countNodes(T->rchild);
}

int xSum(BiTree T, TElemType x) {
    if (T == NULL) {
        return 0;
    }
    
    if (T->data == x) {
        return countNodes(T);
    }
    
    int result = xSum(T->lchild, x);
    if (result > 0) {
        return result;
    }
    
    return xSum(T->rchild, x);
}