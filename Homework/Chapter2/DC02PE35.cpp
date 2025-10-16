#include "allinclude.h"  //DO NOT edit this line

void Inverse(SqList &L) 
{ 
   // 定义一个临时变量用于交换元素
   ElemType temp;
   // i 从表头开始，j 从表尾开始
   int i, j;
   for (i = 0, j = L.length - 1; i < j; ++i, --j) {
       // 交换 L.elem[i] 和 L.elem[j]
       temp = L.elem[i];
       L.elem[i] = L.elem[j];
       L.elem[j] = temp;
   }
}