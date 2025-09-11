#include "allinclude.h"  //DO NOT edit this line
Status StackEmpty_Sq2(SqStack2 S) { 
    // Add your code here
    if (S.top == S.elem) {
        return TRUE;
    } else {
        return FALSE;
    }
}