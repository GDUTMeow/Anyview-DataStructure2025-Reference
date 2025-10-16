#include "allinclude.h"  //DO NOT edit this line

Status GetTop_L(LStack S, ElemType &e) 
{
    // 检查栈是否为空
    // 如果头指针为NULL，则栈为空
    if (S == NULL) {
        return ERROR; // 栈空，无法获取栈顶元素
    }
    
    // 栈非空，栈顶元素即为头结点的数据域
    e = S->data;
    
    return OK; // 操作成功
}