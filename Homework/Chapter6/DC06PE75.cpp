#include "allinclude.h"  //DO NOT edit this line
BSTNode *Ranking(BSTree T, int k) {
    if (k <= 0) {
        return NULL;
    }

    BSTree p = T;
    while (p) {
        if (k == p->lsize) {
            return p;
        } else if (k < p->lsize) {
            p = p->lchild;
        } else {
            k = k - p->lsize;
            p = p->rchild;
        }
    }
    
    return NULL;
}