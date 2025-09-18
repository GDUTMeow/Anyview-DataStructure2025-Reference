#include "RLSMatrix.h"
#include <stdlib.h>

/**
 *  给定一组下标（行, 列），求元素值；如果找不到该元素，则返回0
 */
ElemType getValue(RLSMatrix M, int r,
                  int c) { // 练习1：实现本函数，返回第r行第c列元素的值
  // Add your code here

  for (int i = M.rpos[r]; i < M.rpos[r + 1]; i++) {
    if (M.data[i].j == c) {
      return M.data[i].e;
    }
  }
  return 0;
}

Status
MultSMatrix(RLSMatrix M, RLSMatrix N,
            RLSMatrix &Q) { // 练习2：实现本函数，将矩阵M和N相乘，结果为矩阵Q
                            // Add your code here
  if (M.nu != N.mu) {
    return ERROR; // 矩阵维度不匹配
  }
  for (int i = 1; i <= M.mu; i++) {
    for (int j = 1; j <= N.nu; j++) {
      ElemType sum = 0;
      for (int k = 1; k <= M.nu; k++) {
        sum += getValue(M, i, k) * getValue(N, k, j);
      }
      if (sum != 0) {
        // 将非零元素插入到Q中
        Q.data = (Triple *)realloc(Q.data, (Q.tu + 2) * sizeof(Triple));
        if (Q.data == NULL)
          return OVERFLOW;
        Q.tu++;
        Q.data[Q.tu].i = i;
        Q.data[Q.tu].j = j;
        Q.data[Q.tu].e = sum;
      }
    }
  }

  return OK;
}
