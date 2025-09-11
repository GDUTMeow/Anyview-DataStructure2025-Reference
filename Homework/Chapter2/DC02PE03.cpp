#include "allinclude.h"  //DO NOT edit this line
Status StackEmpty_Sq(SqStack S) { 
    // Add your code here
    if (S.top == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}