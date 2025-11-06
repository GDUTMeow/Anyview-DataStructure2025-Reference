#include "allinclude.h"

void CopyBiTree(BiTree T, BiTree &TT) {
    if (T == NULL) {
        TT = NULL;
        return;
    }

    TT = new BiTNode;
    TT->data = T->data;
    TT->lchild = NULL;
    TT->rchild = NULL;

    LQueue q_orig, q_copy;
    InitQueue_LQ(q_orig);
    InitQueue_LQ(q_copy);

    EnQueue_LQ(q_orig, T);
    EnQueue_LQ(q_copy, TT);

    BiTree p_orig, p_copy;

    while (!QueueEmpty_LQ(q_orig)) {
        DeQueue_LQ(q_orig, p_orig);
        DeQueue_LQ(q_copy, p_copy);

        if (p_orig->lchild) {
            p_copy->lchild = new BiTNode;
            p_copy->lchild->data = p_orig->lchild->data;
            p_copy->lchild->lchild = NULL;
            p_copy->lchild->rchild = NULL;
            EnQueue_LQ(q_orig, p_orig->lchild);
            EnQueue_LQ(q_copy, p_copy->lchild);
        }

        if (p_orig->rchild) {
            p_copy->rchild = new BiTNode;
            p_copy->rchild->data = p_orig->rchild->data;
            p_copy->rchild->lchild = NULL;
            p_copy->rchild->rchild = NULL;
            EnQueue_LQ(q_orig, p_orig->rchild);
            EnQueue_LQ(q_copy, p_copy->rchild);
        }
    }
}