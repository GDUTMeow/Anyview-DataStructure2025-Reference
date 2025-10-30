#include "allinclude.h"  //DO NOT edit this line

void PreOrderKRecursive(BiTree T, int k, int &count, TElemType &result) {
    if (T == NULL || result != '#') {
        return;
    }

    count++;
    if (count == k) {
        result = T->data;
        return;
    }

    PreOrderKRecursive(T->lchild, k, count, result);    // 访问左子树
    PreOrderKRecursive(T->rchild, k, count, result);    // 访问右子树
}

TElemType PreOrderK(BiTree T, int k) 
{   
    int count = 0;
    TElemType result = '#';

    if (k <= 0) {
        return result;
    }

    PreOrderKRecursive(T, k, count, result);
    
    return result;
}