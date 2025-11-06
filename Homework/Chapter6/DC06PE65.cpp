#include "allinclude.h"  //DO NOT edit this line
Status IsBSTree_helper(BSTree T, BSTNode* min_node, BSTNode* max_node) {
    if (T == NULL) {
        return TRUE;
    }

    if (min_node != NULL && T->data.key <= min_node->data.key) {
        return FALSE;
    }

    if (max_node != NULL && T->data.key >= max_node->data.key) {
        return FALSE;
    }

    return IsBSTree_helper(T->lchild, min_node, T) && 
           IsBSTree_helper(T->rchild, T, max_node);
}

Status IsBSTree(BSTree T) {
    return IsBSTree_helper(T, NULL, NULL);
}