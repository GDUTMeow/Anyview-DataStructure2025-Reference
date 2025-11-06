#include "allinclude.h"
void InOrder(TriTree PT, void (*visit)(TElemType))
/* 不使用栈，非递归中序遍历二叉树bt，  */
/* 对每个结点的元素域data调用函数visit */
{
    if (PT == NULL) {
        return;
    }

    TriTree p = PT;

    while (p->lchild != NULL) {
        p = p->lchild;
    }

    while (p != NULL) {
        visit(p->data);

        if (p->rchild != NULL) {
            p = p->rchild;
            while (p->lchild != NULL) {
                p = p->lchild;
            }
        } else {
            while (p->parent != NULL && p == p->parent->rchild) {
                p = p->parent;
            }
            p = p->parent;
        }
    }
}