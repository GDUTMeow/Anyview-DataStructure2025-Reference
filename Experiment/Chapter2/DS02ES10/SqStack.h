#pragma once
typedef int ElemType;
typedef struct {
	ElemType* elem;     // 存储空间的基址
	int top;    // 栈顶元素的下一个位置，简称栈顶位标
	int size;    // 当前分配的存储容量
	int increment;    // 扩容时，增加的存储容量
} SqStack;         // 顺序栈

#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 2
#define FALSE -2

#define INITSIZE 5   //栈的初始容量
#define INCREMENT 2   //栈扩容时的增量

typedef int Status;

Status InitStack_Sq(SqStack& S, int size, int inc);
Status StackEmpty_Sq(SqStack S);
Status Push_Sq(SqStack& S, ElemType e);
Status Pop_Sq(SqStack& S, ElemType& e);