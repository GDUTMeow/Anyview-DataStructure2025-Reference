#include "allinclude.h"

bool findPath(BiTree T, TElemType data, SqStack2 &path) {
    if (T == NULL) {
        return false;
    }

    SElemType node;
    node.ptr = T;
    node.tag = 0;
    Push_Sq2(path, node);

    if (T->data == data) {
        return true;
    }

    if (findPath(T->lchild, data, path)) {
        return true;
    }

    if (findPath(T->rchild, data, path)) {
        return true;
    }

    Pop_Sq2(path, node);
    return false;
}

BiTree CommAncestor(BiTree root, TElemType c1, TElemType c2) {
    if (root == NULL || c1 == c2) {
        return NULL;
    }

    SqStack2 path1, path2;
    InitStack_Sq2(path1);
    InitStack_Sq2(path2);

    bool found1 = findPath(root, c1, path1);
    bool found2 = findPath(root, c2, path2);

    if (!found1 || !found2) {
        return NULL;
    }
    
    int size1 = path1.top - path1.elem;
    int size2 = path2.top - path2.elem;
    
    int i = 0;
    while (i < size1 && i < size2 && path1.elem[i].ptr == path2.elem[i].ptr) {
        i++;
    }

    if (i == 0) {
        return NULL;
    }

    BiTree lca = path1.elem[i - 1].ptr;

    if (lca->data == c1 || lca->data == c2) {
        if (i > 1) {
            return path1.elem[i - 2].ptr;
        } else {
            return NULL;
        }
    } else {
        return lca;
    }
}