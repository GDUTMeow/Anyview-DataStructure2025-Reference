#include "allinclude.h"

bool findPath(BiTree T, TElemType x, Stack& path) {
    if (T == NULL) {
        return false;
    }

    SElemType e;
    e.ptr = T;
    e.tag = 0;
    Push(path, e);

    if (T->data == x) {
        return true;
    }

    if (findPath(T->lchild, x, path)) {
        return true;
    }

    if (findPath(T->rchild, x, path)) {
        return true;
    }

    Pop(path, e);
    return false;
}

BiTree CommAncestor(BiTree T, TElemType a, TElemType b) {
    if (T == NULL || a == b) {
        return NULL;
    }

    Stack path_a, path_b;
    InitStack(path_a);
    InitStack(path_b);

    if (!findPath(T, a, path_a) || !findPath(T, b, path_b)) {
        return NULL;
    }

    int len_a = StackLength(path_a);
    int len_b = StackLength(path_b);

    SElemType* arr_a = new SElemType[len_a];
    for (int k = len_a - 1; k >= 0; k--) {
        Pop(path_a, arr_a[k]);
    }
    SElemType* arr_b = new SElemType[len_b];
    for (int k = len_b - 1; k >= 0; k--) {
        Pop(path_b, arr_b[k]);
    }

    int i = 0;
    while (i < len_a && i < len_b && arr_a[i].ptr == arr_b[i].ptr) {
        i++;
    }
    int lca_index = i - 1;

    BiTree result = NULL;
    if (lca_index >= 0) {
        BiTree lca = arr_a[lca_index].ptr;
        if (lca->data == a || lca->data == b) {
            if (lca_index > 0) {
                result = arr_a[lca_index - 1].ptr;
            }
        } else {
            result = lca;
        }
    }

    delete[] arr_a;
    delete[] arr_b;
    return result;
}