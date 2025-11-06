#include "allinclude.h"

int Width(BiTree T) {
    if (T == NULL) {
        return 0;
    }

    LQueue Q;
    InitQueue_LQ(Q);
    EnQueue_LQ(Q, T);

    int maxWidth = 1;
    int nodesInCurrentLevel = 1;
    int nodesInNextLevel = 0;

    while (!QueueEmpty_LQ(Q)) {
        BiTree p;
        DeQueue_LQ(Q, p);
        nodesInCurrentLevel--;

        if (p->lchild) {
            EnQueue_LQ(Q, p->lchild);
            nodesInNextLevel++;
        }
        if (p->rchild) {
            EnQueue_LQ(Q, p->rchild);
            nodesInNextLevel++;
        }

        if (nodesInCurrentLevel == 0) {
            if (nodesInNextLevel > maxWidth) {
                maxWidth = nodesInNextLevel;
            }
            nodesInCurrentLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
        }
    }

    return maxWidth;
}