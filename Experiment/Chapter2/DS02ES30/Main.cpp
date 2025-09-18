#include <stdio.h>
#include "SqList.h"

void printSqList(SqList L) {
    int i = 0;
    for (i = 0; i < L.length - 1; i++) 
    {
        printf("%d, ", L.elem[i]);
    }
    printf("%d}", L.elem[i]);
    printf("\n");
}

void MergeList_Sq(SqList La, SqList Lb, SqList& Lc);
int getMainElement(SqList L);

int main() 
{
    int aa[4] = {1, 3, 4, 8};
    SqList La = createList_Sq(aa, 4);
    int ab[6] = { 2, 5, 7, 9, 10, 12 };
    SqList Lb = createList_Sq(ab, 6);

    //Part1：两表合并
    MergeList_Sq(La, Lb, Lc);
    printf("Lc = {");
    printSqList(Lc);

    //Part2：求序列的主元素
    SqList L1;
    int a1[7] = { 2, 6, 6, 3, 6, 8, 7 };
    L1 = createList_Sq(a1, 7);
    int result = getMainElement(L1);  //预期结果：-1
    printf("result = %d", result);

    SqList L2;
    int a2[9] = { 2, 6, 6, 3, 6, 8, 6, 7, 6 };
    L2 = createList_Sq(a2, 9);
    result = getMainElement(L2);  //预期结果：6
    printf("result = %d", result);

    SqList L3;
    int a3[8] = { 7, 7, 6, 7, 6, 7, 6, 7 };
    L2 = createList_Sq(a3, 8);
    result = getMainElement(L2);  //预期结果：7
    printf("result = %d", result);

    return 0;
}

//练习4：将顺序表La和Lb合并为Lc
void MergeList_Sq(SqList La, SqList Lb, SqList& Lc) 
{
    int i = 0, j = 0;   
    ElemType ai, bj;
    SqList Lc;
    //练习4.1：创建空表Lc 
    InitList_Sq(Lc, La.length + Lb.length, 10);

    while (i < La.length && j < Lb.length)  // 表La和Lb均非空
    {      
      //练习4.2：两表合并 
      //Add your code here 
    if (La.elem[i] <= Lb.elem[j]) {
        Append_Sq(Lc, La.elem[i]);
        i++;
    } else {
        Append_Sq(Lc, Lb.elem[j]);
        j++;
    }

}

    //练习4.3：处理“La未空，但Lb已空”的情况
    while (j == Lb.length && i < La.length) {
       Append_Sq(Lc, La.elem[i]);
       i++;
    }

    //练习4.4：处理“La已空，但Lb未空”的情况
    while (i == La.length && j < Lb.length) {
       Append_Sq(Lc, Lb.elem[j]);
       j++;
    }

}

//练习5：求序列A中的主元素，如果A没有主元素，则返回-1
int getMainElement(SqList L)
{
    //Add your code here
    int i, count = 1;
    ElemType candidate = L.elem[0];
    for (i = 1; i < L.length; i++) {
        if (L.elem[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = L.elem[i];
                count = 1;
            }
        }
    }

    // 验证候选元素是否为主元素
    count = 0;
    for (i = 0; i < L.length; i++) {
        if (L.elem[i] == candidate) {
            count++;
        }
    }
    if (count > L.length / 2) {
        return candidate;
    }
    return -1; // 没有主元素
}