#include "allinclude.h"
int NodeLevel(BiTree t, TElemType x) {
    if (t == NULL) {
        return -1;
    }

    if (t->data == x) {
        return 1;
    }

    int leftLevel = NodeLevel(t->lchild, x);
    if (leftLevel != -1) {
        return leftLevel + 1;
    }

    int rightLevel = NodeLevel(t->rchild, x);
    if (rightLevel != -1) {
        return rightLevel + 1;
    }

    return -1;
}