#include "allinclude.h"

int LevelSum(BiTree T) {
    if (T == NULL) {
        return 0;
    }

    LQueue Q;
    InitQueue_LQ(Q);
    EnQueue_LQ(Q, T);

    int count = 0;
    BiTree p;

    while (!QueueEmpty_LQ(Q)) {
        DeQueue_LQ(Q, p);
        count++;

        if (p->lchild) {
            EnQueue_LQ(Q, p->lchild);
        }
        if (p->rchild) {
            EnQueue_LQ(Q, p->rchild);
        }
    }

    return count;
}