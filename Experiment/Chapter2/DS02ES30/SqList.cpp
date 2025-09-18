#include <stdlib.h>
#include "SqList.h"

//练习1：初始化一个空的顺序表L
Status InitList_Sq(SqList& L, int size, int inc) 
{ 
    //Add your code here
    L.elem = (ElemType*)malloc(size * sizeof(ElemType));
    if (NULL == L.elem) return OVERFLOW;
    L.length = 0;
    L.size = size;
    L.increment = inc;
    return OK;
}

//练习2：获取第i个元素的值，用参数e返回该值
Status GetElem_Sq(SqList L, int i, ElemType& e) 
{
    if (i > L.length || 0 == L.length) {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
}

//练习3：在顺序表L表尾添加元素e
Status  Append_Sq(SqList& L, ElemType e) 
{         
    ElemType* newbase;
    if (L.length >= L.size) {  // 扩容
        //Add your code here
        newbase = (ElemType*)realloc(L.elem, (L.size + L.increment) * sizeof(ElemType));
        if (NULL == newbase) return OVERFLOW;
        L.elem = newbase;
        L.size += L.increment;
    }
    //Add your code here
    L.elem[L.length] = e;
    L.length++;
    return OK;
}

/**
  * 创建一个顺序表
  * @param a[]：数组中的每一个元素作为顺序表中的元素
  * @param n: 数组中的长度
  */
SqList createList_Sq(int a[], int n)
{
    SqList L;
    InitList_Sq(L, n, 10);
    for (int i = 0; i < n; i++)
    {
        Append_Sq(L, a[i]);
    }

    return L;
}