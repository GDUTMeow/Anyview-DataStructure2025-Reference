#include "allinclude.h"
int getCompleteTreeHeight(BiTree T) {
    int height = 0;
    while (T) {
        height++;
        T = T->lchild;
    }
    return height;
}

BiTNode* getLastNode(BiTree T) {
    if (T == NULL) {
        return NULL;
    }

    BiTree p = T;
    while (p->lchild != NULL) {
        int leftHeight = getCompleteTreeHeight(p->lchild);
        int rightHeight = getCompleteTreeHeight(p->rchild);

        if (leftHeight == rightHeight) {
            p = p->rchild;
        } else {
            p = p->lchild;
        }
    }
    return p;
}