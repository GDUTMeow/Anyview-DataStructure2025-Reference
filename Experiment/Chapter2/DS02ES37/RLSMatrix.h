#ifndef _RLSMATRIX_H
#define _RLSMATRIX_H
#include "Triple.h"

typedef struct {
  Triple *data;  // 非零元三元组表，0号单元未用
  int* rpos; // 指示各行的起始位置
  int mu, nu, tu; // 矩阵的行数、列数和非零元个数
} RLSMatrix;


ElemType getValue(RLSMatrix M, int r, int c);
Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix& Q);

#endif
