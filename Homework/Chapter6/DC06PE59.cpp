#include "allinclude.h"
void xLevel(BiTree T, TElemType x, bool &found, int &xlev) {
    if (T == NULL || found) {
        return;
    }

    if (T->data == x) {
        found = true;
        xlev = 1;
        return;
    }

    xLevel(T->lchild, x, found, xlev);
    if (found) {
        xlev++;
        return;
    }

    xLevel(T->rchild, x, found, xlev);
    if (found) {
        xlev++;
        return;
    }
}