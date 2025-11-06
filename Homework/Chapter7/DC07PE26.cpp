#include "allinclude.h"  //DO NOT edit this line
int TreeDepth(CSTree T) {
    if (T == NULL) {
        return 0;
    }
    
    int firstChildDepth = TreeDepth(T->firstChild);
    int nextSiblingDepth = TreeDepth(T->nextSibling);
    
    int currentTreeDepth = 1 + firstChildDepth;

    if (currentTreeDepth > nextSiblingDepth) {
        return currentTreeDepth;
    } else {
        return nextSiblingDepth;
    }
}