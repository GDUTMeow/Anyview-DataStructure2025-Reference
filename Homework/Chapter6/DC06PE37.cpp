#include "allinclude.h"

TElemType findParent(BiTree T, TElemType data, BiTNode* parent) {
    if (T == NULL) {
        return '\0';
    }

    if (T->data == data) {
        if (parent != NULL) {
            return parent->data;
        } else {
            return '\0';
        }
    }

    TElemType result = findParent(T->lchild, data, T);
    if (result != '\0') {
        return result;
    }

    return findParent(T->rchild, data, T);
}