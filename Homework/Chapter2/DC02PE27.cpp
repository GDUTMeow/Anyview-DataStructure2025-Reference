#include "allinclude.h"  //DO NOT edit this line

Status EnCQueue(CLenQueue &Q, ElemType x) { 
    // 当队列长度等于最大尺寸时，队列已满
    if (Q.length == MAXQSIZE) {
        return ERROR;
    }
    // 队尾指针循环后移一位
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    // 在新的队尾位置插入元素
    Q.elem[Q.rear] = x;
    // 队列长度加一
    Q.length++;
    return OK;
}

Status DeCQueue(CLenQueue &Q, ElemType &x){
    // 当队列长度为0时，队列为空
    if (Q.length == 0) {
        return ERROR;
    }
    // 计算队头元素的索引
    // 队头索引 = (队尾索引 - 队列长度 + 1 + 队列最大容量) % 队列最大容量
    int front_index = (Q.rear - Q.length + 1 + MAXQSIZE) % MAXQSIZE;
    // 取出队头元素
    x = Q.elem[front_index];
    // 队列长度减一
    Q.length--;
    return OK;
}