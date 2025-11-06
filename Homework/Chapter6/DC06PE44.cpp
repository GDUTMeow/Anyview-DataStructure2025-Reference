#include "allinclude.h"
int calculate_depth_helper(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int left_depth = calculate_depth_helper(T->lchild);
    int right_depth = calculate_depth_helper(T->rchild);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

int Depthx(BiTree T, TElemType x) {
    if (T == NULL) {
        return 0;
    }
    if (T->data == x) {
        return calculate_depth_helper(T);
    }
    int depth = Depthx(T->lchild, x);
    if (depth != 0) {
        return depth;
    }
    return Depthx(T->rchild, x);
}