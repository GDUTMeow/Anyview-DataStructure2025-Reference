#include "allinclude.h"  //DO NOT edit this line
Status InitStack_Sq2(SqStack2 &S, int size, int inc) { 
    // Add your code here
    if (size <= 0 || inc <= 0) return ERROR;
    S.elem = (ElemType *)malloc(size * sizeof(ElemType));
    if (S.elem == NULL) {
        return ERROR;
    }
    S.top = S.elem;
    S.size = size;
    S.increment = inc;
    return OK;
}
