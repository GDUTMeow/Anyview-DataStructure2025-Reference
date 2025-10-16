#include "allinclude.h"  //DO NOT edit this line

Status QueueEmpty_LQ(LQueue Q)
{
    // 对于带头结点的链队列，当头指针和尾指针指向同一个结点（头结点）时，队列为空
    if (Q.front == Q.rear && Q.front == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}