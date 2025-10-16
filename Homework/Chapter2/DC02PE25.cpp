#include "allinclude.h" //DO NOT edit this line

Status EnCQueue(CTagQueue &Q, ElemType x) {
  // 当头尾指针相同且tag为1时，队列已满
  if (Q.front == Q.rear && Q.tag == 1) {
    return ERROR;
  }
  // 在队尾插入元素
  Q.elem[Q.rear] = x;
  // 队尾指针循环后移一位
  Q.rear = (Q.rear + 1) % MAXQSIZE;
  // 如果入队后头尾指针重合，说明队列已满，设置tag为1
  if (Q.rear == Q.front) {
    Q.tag = 1;
  }
  return OK;
}

Status DeCQueue(CTagQueue &Q, ElemType &x) {
  // 当头尾指针相同且tag为0时，队列为空
  if (Q.front == Q.rear && Q.tag == 0) {
    return ERROR;
  }
  // 取出队头元素
  x = Q.elem[Q.front];
  // 队头指针循环后移一位
  Q.front = (Q.front + 1) % MAXQSIZE;
  // 出队后队列不可能为满，故设置tag为0
  Q.tag = 0;
  return OK;
}