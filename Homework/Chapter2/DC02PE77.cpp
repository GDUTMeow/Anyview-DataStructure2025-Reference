#include "allinclude.h"  //DO NOT edit this line
int ListLength_L(LinkList L)
{
    // 若L不是带头结点单链表，则返回-1
    if (L == NULL) {
        return -1;
    }

    int length = 0;
    LinkList p = L->next; // p指向第一个数据节点
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}