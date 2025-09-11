#include "allinclude.h"  //DO NOT edit this line
LinkList MakeNode(ElemType x) { 
    // Add your code here
    LinkList node = (LinkList)malloc(sizeof(LNode));
    if (node == NULL) {
        return NULL;
    }
    node->data = x;
    node->next = NULL;
    return node;
}