#include <stdio.h>
#include <string.h>
#include "SqStack.h"

void Conversion(int N) {
    SqStack S;
    ElemType e;
    InitStack_Sq(S, INITSIZE, INCREMENT); // 栈S的初始容量为MAXSIZE

    while (N != 0)
    {
        Push_Sq(S, N % 8);  // 将N除以8的余数入栈
        N /= 8;             // N取值为其除以8的商
    }
    while (TRUE != StackEmpty_Sq(S))
    { // 依次输出栈中的余数
        Pop_Sq(S, e);
        printf("%d", e);
    }
}



//练习4：回文判定
Status isPlalindrome(char* exp)
{// 如果exp是合法的回文，返回TRUE；否则返回FALSE；
    SqStack S;
    InitStack_Sq(S, INITSIZE, 5);
    // Add your code here
    int length = strlen(exp);
    for (int i = 0; i < length; i++) {
        Push_Sq(S, exp[i]);
    }
    ElemType ch;
    for (int i = 0; i < length; i++) {
        Pop_Sq(S, ch);
        if (ch != exp[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

int main() 
{
    // Part 1：进栈、出栈
    SqStack S;
    InitStack_Sq(S, INITSIZE, INCREMENT);
    Push_Sq(S, 1);  // 进栈
    for(int i = 2; i <= 6; i++)
	{
        Push_Sq(S, i);  // 进栈
    }
		
    ElemType e;
    Pop_Sq(S, e);   //出栈
    if (StackEmpty_Sq(S))  //判断栈是否为空
    {
        printf("栈空！\n");
    }
    Pop_Sq(S, e);   //栈为空时，再出栈一次，会有什么现象？


    // Part 2：数值转换
    Conversion(1348);


    // Part 3：回文判定
    Status result;

    //// 测试情况1，预期返回TRUE
    char str310[] = "a";
    result = isPlalindrome(str310);

    //// 测试情况2，预期返回TRUE
    char str320[] = "abba";
    result = isPlalindrome(str310);

    //// 测试情况3，预期返回TRUE
    char str330[] = "abbba";
    char str331[] = "abcba";
    char str332[] = "bcbccbcb";
    result = isPlalindrome(str330);


    //// 测试情况4，预期返回FALSE
    char str340[] = "abcbba";
    result = isPlalindrome(str340);
    char str341[] = "abccb";
    result = isPlalindrome(str341);
    char str342[] = "bcbcbc";
    result = isPlalindrome(str342);


  
    return 0;
}
