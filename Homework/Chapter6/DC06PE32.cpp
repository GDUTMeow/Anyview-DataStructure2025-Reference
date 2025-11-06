#include "allinclude.h"
void PostOrder(BiTree bt, void (*visit)(TElemType)) {
/* 使用栈，非递归后序遍历二叉树bt，    */
/* 对每个结点的元素域data调用函数visit */
    SqStack2 S;
    BiTree p = bt;
    SElemType e;

    if (bt == NULL) {
        return;
    }

    InitStack_Sq2(S);

    while (p != NULL || !StackEmpty_Sq2(S)) {
        while (p != NULL) {
            e.ptr = p;
            e.tag = 0;
            Push_Sq2(S, e);
            p = p->lchild;
        }

        if (!StackEmpty_Sq2(S)) {
            GetTop_Sq2(S, e);
            if (e.tag == 0) {
                Pop_Sq2(S, e);
                e.tag = 1;
                Push_Sq2(S, e);
                p = e.ptr->rchild;
            } else {
                Pop_Sq2(S, e);
                visit(e.ptr->data);
                p = NULL;
            }
        }
    }
}