#include <stdio.h>
#include "CircularQueue.h"

int main() {    
    SqQueue Q;
    ElemType e;
    Status result1, result2;
    
    //1. 初始化一个size为5的循环队列Q
    InitQueue_Sq(Q, 5);
    EnQueue_Sq(Q, 'A'); 
    EnQueue_Sq(Q, 'B'); 
    EnQueue_Sq(Q, 'C');    
    EnQueue_Sq(Q, 'D');
    DeQueue_Sq(Q, e);   
    EnQueue_Sq(Q, 'E');  
    DeQueue_Sq(Q, e);   
    EnQueue_Sq(Q, 'F');   //出现了要用求余确定来确定新进队列的元素位置，
                          //即“循环使用空间的情况”   
    result1 = EnQueue_Sq(Q, 'G');   //满了，放不下
   
    printf("result1 = %d\n", result1);
                                               
    DeQueue_Sq(Q, e);   
    DeQueue_Sq(Q, e);   
    DeQueue_Sq(Q, e);   
    DeQueue_Sq(Q, e);   
    result2 = DeQueue_Sq(Q, e);   //空了，return FALSE      
      
    printf("result2 = %d\n", result2);
                                          
    if (TRUE == QueueEmpty_Sq(Q))
    {
        printf("Q is empty.\n");
    }
    else
    {
        printf("Q is not empty.\n");
    }

    //Part3：将队列中的元素逆置，
    EnQueue_Sq(Q, 'A');
    EnQueue_Sq(Q, 'B');
    EnQueue_Sq(Q, 'C');

    reverseQueue_Sq(Q);  //将队列中的元素逆置，预期结果：CBA
    while(FALSE == QueueEmpty_Sq(Q)) {
        DeQueue_Sq(Q, e);
        printf("%c ", e);
    }

    return 0;
}
