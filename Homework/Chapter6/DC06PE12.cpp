#include "allinclude.h"  //DO NOT edit this line
int Leaves(BiTree T) 
{   // Add your code here
    if (T == NULL) {
        return 0; // 空树
    }

    if (T->lchild == NULL && T->rchild == NULL) {
        return 1;   // 无左右孩子，自己就是叶子
    }

    return Leaves(T->lchild) + Leaves(T->rchild);
}