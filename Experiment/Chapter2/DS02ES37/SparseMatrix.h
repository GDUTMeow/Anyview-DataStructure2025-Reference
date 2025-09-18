#ifndef _SPARSEMATRIX_H
#define _SPARSEMATRIX_H
#include "Triple.h"

typedef struct {
  Triple *data;  // 非零元三元组表，0号单元未用
  int mu, nu, tu; // 矩阵的行数、列数和非零元个数
} TSMatrix;


Status FastTransposeSMatrix(TSMatrix M, TSMatrix& T);
Status MultSMatrix(TSMatrix M, TSMatrix K, TSMatrix& P);

#endif