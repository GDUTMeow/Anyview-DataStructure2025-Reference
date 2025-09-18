#ifndef _TRIPLE_H
#define _TRIPLE_H

typedef int ElemType;

#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 2
#define FALSE -2

typedef int Status;

typedef struct {
  int i, j ; // 非零元的行和列
  ElemType e; // 非零元的值
} Triple;

#endif