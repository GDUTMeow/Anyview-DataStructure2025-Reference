#include "allinclude.h"  //DO NOT edit this line
int QueueLength_LQ(LQueue Q) 
{   // Add your code here
    int len = 1;
    if (Q.front == Q.rear && Q.front == NULL) return 0;
    while (Q.front != Q.rear) {
        Q.front = Q.front->next;
        ++len;
    }
    return len;
}