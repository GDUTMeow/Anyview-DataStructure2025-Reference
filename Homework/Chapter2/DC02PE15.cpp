#include "allinclude.h"  //DO NOT edit this line
Status Push_Sq2(SqStack2 &S, ElemType e) { 
    // Add your code here
    if (S.top - S.elem >= S.size) {
        ElemType *newBase = (ElemType *)realloc(S.elem, (S.size + S.increment) * sizeof(ElemType));
        if (newBase == NULL) {
            return ERROR;
        }
        S.elem = newBase;
        S.top = S.elem + S.size;
        S.size += S.increment;
    }
    *(S.top++) = e;
    return OK;
}