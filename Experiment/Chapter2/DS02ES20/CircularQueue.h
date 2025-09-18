#include "stdlib.h"

#define OVERFLOW -1
#define OK 1
#define ERROR 0    
#define TRUE 2
#define FALSE -2

typedef char ElemType;
typedef struct {
   ElemType  *base;  // 存储空间的基址
   int front;        // 队头位标
   int rear;         // 队尾位标，指示队尾元素的下一位置
   int maxSize;      // 最大长度
} SqQueue;



typedef int Status;

Status InitQueue_Sq(SqQueue& Q, int size);
Status EnQueue_Sq(SqQueue& Q, ElemType e);
Status DeQueue_Sq(SqQueue& Q, ElemType& e);
Status QueueEmpty_Sq(SqQueue Q);
void reverseQueue_Sq(SqQueue& Q);




