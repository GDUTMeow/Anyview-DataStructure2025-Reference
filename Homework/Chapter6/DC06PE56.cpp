#include "allinclude.h"
Status SearchX(BiTree T, TElemType x) {
    if (T == NULL) {
        return ERROR;
    }

    if (T->data == x) {
        return OK;
    }

    if (SearchX(T->lchild, x) == OK) {
        return OK;
    }

    return SearchX(T->rchild, x);
}