#include "allinclude.h"  //DO NOT edit this line
void PreOrder(BiTree T, Status (*visit)(TElemType)) {
    Stack S;
    BiTree p;

    if (T == NULL) {
        return;
    }

    InitStack(S);
    Push(S, T);

    while (!StackEmpty(S)) {
        Pop(S, p);
        visit(p->data);

        if (p->rchild) {
            Push(S, p->rchild);
        }
        if (p->lchild) {
            Push(S, p->lchild);
        }
    }
}