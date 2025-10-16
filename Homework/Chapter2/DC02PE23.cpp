#include "allinclude.h"  //DO NOT edit this line
int QueueLength_Sq(SqQueue Q) { 
    // Add your code here
    if (Q.front == Q.rear) return 0;
    int length = (Q.rear - Q.front + Q.maxSize) % Q.maxSize;
    return length;
}