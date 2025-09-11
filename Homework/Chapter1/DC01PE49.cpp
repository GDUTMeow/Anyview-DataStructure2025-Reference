#include "allinclude.h"  //DO NOT edit this line
Status CreateSequence(Sequence &S, int n, ElemType *a) { 
   // Add your code here
    if (n == 0) return ERROR;
    S.length = n;
    S.elem = (ElemType *)malloc(n * sizeof(ElemType));
    if (S.elem == NULL) {
        return ERROR;
    }
    for (int i = 0; i < n; i++) {
        S.elem[i] = a[i];
    }
    return OK;
}