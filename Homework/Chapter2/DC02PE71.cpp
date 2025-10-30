#include "allinclude.h"  //DO NOT edit this line
Status ListEmpty_L(LinkList L) 
{    // Add your code here
    // 判断头结点的next指针是否为空
    if (L->next == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}