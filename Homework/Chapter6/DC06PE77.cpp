#include "allinclude.h"  //DO NOT edit this line
int Depth_BF(BBSTree T) {
    if (T == NULL) {
        return 0;
    }

    int left_height = Depth_BF(T->lchild);
    int right_height = Depth_BF(T->rchild);

    T->bf = left_height - right_height;

    return (left_height > right_height ? left_height : right_height) + 1;
}