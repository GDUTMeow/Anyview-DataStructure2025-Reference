#include "allinclude.h"  //DO NOT edit this line
LinkList CreateOrdLList(ElemType x, ElemType y) { 
    // Add your code here
    LinkList head = (LinkList)malloc(sizeof(LNode));
    if (head == NULL) {
        return NULL;
    }
    head->data = x;
    head->next = (LinkList)malloc(sizeof(LNode));
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    head->next->data = y;
    head->next->next = NULL;
    // 升序排序
    if (x > y) {
        ElemType tmp = head->data;
        head->data = head->next->data;
        head->next->data = tmp;
    }
    return head;
}
