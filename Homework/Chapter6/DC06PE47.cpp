#include "allinclude.h"

void LevelOrder(BiTree bt, char *ss) {
    if (bt == NULL) {
        ss[0] = '\0';
        return;
    }

    LQueue Q;
    InitQueue_LQ(Q);
    EnQueue_LQ(Q, bt);

    BiTree p;
    int i = 0;

    while (!QueueEmpty_LQ(Q)) {
        DeQueue_LQ(Q, p);
        ss[i++] = p->data;

        if (p->lchild) {
            EnQueue_LQ(Q, p->lchild);
        }
        if (p->rchild) {
            EnQueue_LQ(Q, p->rchild);
        }
    }
    ss[i] = '\0';
}