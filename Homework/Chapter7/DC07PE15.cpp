#include "allinclude.h"  //DO NOT edit this line
int Leave(CSTree T) {
    if (T == NULL) {
        return 0;
    }

    if (T->firstChild == NULL) {
        return 1 + Leave(T->nextSibling);
    } else {
        return Leave(T->firstChild) + Leave(T->nextSibling);
    }
}