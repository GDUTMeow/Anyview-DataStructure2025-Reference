#include "allinclude.h"
void PostOrder(TriTree bt, void (*visit)(TElemType))
/* 不使用栈，非递归后序遍历二叉树bt，  */
/* 对每个结点的元素域data调用函数visit */
{  // Add your code here
    if (bt == NULL) {
        return;
    }

    TriTree p = bt;

    while (p != NULL) {
        switch (p->mark) {
            case 0:
                p->mark = 1;
                if (p->lchild != NULL) {
                    p = p->lchild;
                }
                break;
            
            case 1:
                p->mark = 2;
                if (p->rchild != NULL) {
                    p = p->rchild;
                }
                break;

            case 2:
                visit(p->data);
                p->mark = 0;
                p = p->parent;
                break;
        }
    }
}