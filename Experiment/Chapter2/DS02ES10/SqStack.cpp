#include <stdlib.h>
#include "SqStack.h"

Status InitStack_Sq(SqStack& S, int size, int inc) { // 初始化空顺序栈S
    S.elem = (ElemType*)malloc(size * sizeof(ElemType)); // 分配存储空间
    if (NULL == S.elem) return OVERFLOW;
    S.top = 0;       // 置S为空栈
    S.size = size;  // 初始容量值
    S.increment = inc; // 初始增量值
    return OK;
}

//练习1：进栈
Status Push_Sq(SqStack& S, ElemType e) { // 元素e压入栈S
    ElemType* newbase;
    if (S.top >= S.size) { // 若栈顶位标已到达所分配的容量，则栈满，扩容
        newbase = (ElemType*)realloc(S.elem, (S.size + S.increment) * sizeof(ElemType));
        if (NULL == newbase) return OVERFLOW;
        //Add your code here: 调整S.elem和S.size
        S.elem = newbase;
        S.size += S.increment;
    }
    //Add your code here: e入栈，并将S.top加1
    S.elem[S.top++] = e;
    return OK;
}

//练习2：出栈
Status Pop_Sq(SqStack& S, ElemType& e) { // 栈顶元素出栈，赋给元素e
    //add your code here
    if (0 == S.top) return ERROR;
    //Add your code here: e出栈，并将S.top减1
    e = S.elem[--S.top];
    return OK;
}

//练习3：改正本函数中的错误
Status StackEmpty_Sq(SqStack S) { // 判断栈S是否空，若空则返回TRUE，否则FALSE
    if (0 == S.top)
        return TRUE;
    else
        return FALSE;
}