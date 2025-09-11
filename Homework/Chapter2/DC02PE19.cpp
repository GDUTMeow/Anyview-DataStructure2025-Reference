#include "allinclude.h"  //DO NOT edit this line
Status CopyStack_Sq(SqStack S1, SqStack &S2) { 
    // Add your code here
    // 初始化临时栈用于存储 S1 中的元素
    SqStack tempStack;
    tempStack.elem = (ElemType *)malloc(S1.size * sizeof(ElemType));
    if (tempStack.elem == NULL) {
        return ERROR;
    }
    tempStack.top = 0;
    tempStack.size = S1.size;
    // 将 S1 中的元素依次弹出并压入临时栈
    ElemType e;
    while (S1.top > 0) {
        Pop_Sq(S1, e);
        Push_Sq(tempStack, e);
    }
    // 初始化 S2
    S2.elem = (ElemType *)malloc(tempStack.size * sizeof(ElemType));
    if (S2.elem == NULL) {
        free(tempStack.elem);
        return ERROR;
    }
    S2.top = 0;
    S2.size = tempStack.size;
    // 将临时栈中的元素依次弹出并压入 S2
    while (tempStack.top > 0) {
        Pop_Sq(tempStack, e);
        Push_Sq(S2, e);
    }
    // 释放临时栈
    free(tempStack.elem);
    return OK;
}
