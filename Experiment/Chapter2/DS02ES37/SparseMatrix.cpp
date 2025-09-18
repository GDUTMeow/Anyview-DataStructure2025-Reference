#include "SparseMatrix.h"
#include <stdlib.h>

Status FastTransposeSMatrix(TSMatrix M, TSMatrix &T) {
  // 采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T
  int j, p, q, t;
  int *num;  // 保存每一列中的非零元个数
  int *cpos; // 保存转置后每列第一非零元应当在T中所处的序号

  // 练习1：矩阵T初始化：T.mu、T.nu和T.tu分别应当被初始化为什么值？
  // Add your code here

  T.data = (Triple *)malloc(sizeof(Triple) * (T.tu + 1));

  num = (int *)malloc((M.nu + 1) * sizeof(int));
  cpos = (int *)malloc((M.nu + 1) * sizeof(int));
  if (NULL == num || NULL == cpos)
    return OVERFLOW;

  if (T.tu != 0) {
    for (j = 1; j <= M.nu; ++j) // 初始化num向量
      num[j] = 0;
    for (t = 1; t <= M.tu;
         ++t) // 练习2：求M中每一列所含非零元的个数，存放于num中
    {
      j = M.data[t].j;
      num[j]++;
    }
    cpos[1] = 1;
    for (j = 2; j <= M.nu; ++j) // 练习3：求每一列的第一个非零元在b.data中的序号
      cpos[j] = cpos[j - 1] + num[j - 1];

    for (p = 1; p <= M.tu; ++p) { // 转置矩阵元素
      j = M.data[p].j;
      q = cpos[j]; // cpos[j]指向第j列第一个非零元的位置

      // 练习4：转置元素
      // Add your code here
      T.data[q].i = M.data[p].j;
      T.data[q].j = M.data[p].i;
      T.data[q].e = M.data[p].e;
      cpos[j]++;

      // 练习5：令cpos[j]指向第j列下一个非零元的位置
      // Add your code here;
      cpos[j]++;
    }
  }

  free(num);
  free(cpos);
  return OK;
}