#include "allinclude.h"  //DO NOT edit this line
Status Pop_Sq2(SqStack2 &S, ElemType &e) { 
    // Add your code here
    if (S.top == S.elem) {
        return ERROR;
    }
    e = *(--S.top);
    return OK;
}