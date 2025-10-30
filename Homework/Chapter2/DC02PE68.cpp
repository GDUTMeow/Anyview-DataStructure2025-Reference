#include "allinclude.h"             //DO NOT edit this line
Status InitCLQueue(CLQueue &rear) { // Add your code here
  // 创建头结点
  rear = (CLQueue)malloc(sizeof(CLQNode));
  if (!rear) {
    return ERROR;
  }
  // 空循环链表的头结点指向自身
  rear->next = rear;
  return OK;
}

Status EnCLQueue(CLQueue &rear, ElemType x) { // Add your code here
  // 创建新结点
  CLQNode *p = (CLQNode *)malloc(sizeof(CLQNode));
  if (!p) {
    return ERROR;
  }
  p->data = x;
  // 新结点插入到队尾，成为新的队尾结点
  p->next = rear->next;
  rear->next = p;
  // rear指针始终指向队尾
  rear = p;
  return OK;
}

Status DeCLQueue(CLQueue &rear, ElemType &x) { // Add your code here
  // 检查队列是否为空
  if (rear->next == rear) {
    return ERROR;
  }
  // p指向队头结点 (头结点的下一个结点)
  CLQNode *p = rear->next->next;
  x = p->data;
  // 头结点指向队头结点的下一个结点
  rear->next->next = p->next;
  // 如果队列中只有一个元素，删除后需要更新rear指针指向头结点
  if (p == rear) {
    rear = rear->next;
  }
  free(p);
  return OK;
}