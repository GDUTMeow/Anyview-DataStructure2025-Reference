#include "allinclude.h"  //DO NOT edit this line
Status GetTop_Sq(SqStack S, ElemType &e) 
{// Add your code here
    if (S.top == 0) {
        return ERROR;
    }
    e = S.elem[S.top - 1];
    return OK;
}