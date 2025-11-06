#include "allinclude.h"

Status CompleteBiTree(BiTree bt) {
    if (bt == NULL) {
        return TRUE;
    }

    LQueue Q;
    InitQueue_LQ(Q);
    EnQueue_LQ(Q, bt);

    BiTree p;
    bool must_be_leaf = false;

    while (!QueueEmpty_LQ(Q)) {
        DeQueue_LQ(Q, p);

        if (p->lchild) {
            if (must_be_leaf) {
                return FALSE;
            }
            EnQueue_LQ(Q, p->lchild);
        } else {
            must_be_leaf = true;
        }

        if (p->rchild) {
            if (must_be_leaf) {
                return FALSE;
            }
            EnQueue_LQ(Q, p->rchild);
        } else {
            must_be_leaf = true;
        }
    }

    return TRUE;
}