#include "SqStack.h"
#include "CircularQueue.h"
#include <stdio.h>

//练习1：初始化一个空的循环队列
Status InitQueue_Sq(SqQueue& Q, int size) { // 构造一个空队列
   //Add your code here
    Q.base = (ElemType*)malloc(size * sizeof(ElemType));
    if (NULL == Q.base) return OVERFLOW;
    Q.front = 0;
    Q.rear = 0;
    Q.maxSize = size;
    return OK;
}

//练习2（改错）：进队列操作
Status EnQueue_Sq(SqQueue& Q, ElemType e) {
    // 若当前队列不满，在队列的尾元素之后，插入元素 e 为新的队列尾元素

    if (Q.front == (Q.rear + 1) % Q.maxSize) // 队满报错
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.maxSize; // Q.rear循环加1
    return OK;
}

//练习3（改错）：出队列操作
Status DeQueue_Sq(SqQueue& Q, ElemType& e) {
    // 若队列不空，则删除队列Q中的头元素，用 e 返回其值
    if (Q.front == Q.rear)
        return ERROR; // 队空报错
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % Q.maxSize; // Q.front循环加1
    return OK;
}

//练习4（改错）：判断队列是否为空
Status QueueEmpty_Sq(SqQueue Q) { // 判断队列Q是否空，若空则返回TRUE，否则FALSE
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//练习5：将队列中的元素逆置
void reverseQueue_Sq(SqQueue& Q)
{  
    SqStack s;
    InitStack_Sq(s, Q.maxSize, INCREMENT);
    ElemType e;
    while (FALSE == QueueEmpty_Sq(Q)) {
        DeQueue_Sq(Q, e);
        Push_Sq(s, e);
    }
    while (FALSE == StackEmpty_Sq(s)) {
        Pop_Sq(s, e);
        EnQueue_Sq(Q, e);
    }
}