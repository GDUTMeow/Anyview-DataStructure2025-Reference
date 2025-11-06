#include "allinclude.h"  //DO NOT edit this line
Status Similar(BiTree T1, BiTree T2) {
    if (T1 == NULL && T2 == NULL) {
        return TRUE;
    } else if (T1 != NULL && T2 != NULL) {
        return (Similar(T1->lchild, T2->lchild) && Similar(T1->rchild, T2->rchild));
    } else {
        return FALSE;
    }
}