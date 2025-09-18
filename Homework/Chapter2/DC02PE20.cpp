#include "allinclude.h"
void Conversion(int N, int rd)
{  // Add your code here
    // 将整数 rd 转换为指定的进制，并打印，rd 取 2～9
    SqStack s;
    InitStack_Sq(s, MAXSIZE, INCREMENT);
    int origin = N;
    if (rd == 10) {
        printf("%d", N);
        return;
    }
    do {
        ElemType remainder = N % rd;
        Push_Sq(s, remainder);
        N /= rd;
    } while (N > 0);
    while (!StackEmpty_Sq(s)) {
        ElemType digit;
        Pop_Sq(s, digit);
        printf("%d", digit);
    }
}