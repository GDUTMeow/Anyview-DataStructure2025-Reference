#include "allinclude.h"  //DO NOT edit this line

Status StackEmpty_L(LStack S) 
{
    // 如果链栈的头指针为NULL，则表示栈为空
    if (S == NULL) {
        return TRUE;
    } 
    // 否则，栈不为空
    else {
        return FALSE;
    }
}