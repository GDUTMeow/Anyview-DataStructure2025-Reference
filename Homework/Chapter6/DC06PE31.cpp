#include "allinclude.h"
void PreOrder(BiTree bt, void (*visit)(TElemType)) {
    SqStack2 S;
    BiTree p;

    if (bt == NULL) {
        return;
    }

    InitStack_Sq2(S);
    Push_Sq2(S, bt);

    while (!StackEmpty_Sq2(S)) {
        Pop_Sq2(S, p);
        visit(p->data);

        if (p->rchild) {
            Push_Sq2(S, p->rchild);
        }
        if (p->lchild) {
            Push_Sq2(S, p->lchild);
        }
    }
}