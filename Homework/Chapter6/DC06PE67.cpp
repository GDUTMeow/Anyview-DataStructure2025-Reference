#include "allinclude.h"

Status InsertBST_I(BSTree &T, TElemType k) {
    if (T == NULL) {
        T = new BSTNode;
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
        return OK;
    }

    BSTree p = T;
    BSTree parent = NULL;

    while (p != NULL) {
        parent = p;
        if (k.key == p->data.key) {
            return ERROR;
        } else if (k.key < p->data.key) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }

    BSTree newNode = new BSTNode;
    newNode->data = k;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    if (k.key < parent->data.key) {
        parent->lchild = newNode;
    } else {
        parent->rchild = newNode;
    }

    return OK;
}