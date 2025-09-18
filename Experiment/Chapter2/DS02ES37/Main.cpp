#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"
#include "RLSMatrix.h"
#include "Triple.h"

/*
0  14   0   0  -5
0  -7   0   0   0
36   0   0  28   0

mu = 3; nu = 5; tu = 5
*/
Status CreateSparseMatrixM1(TSMatrix& M) { // 创建稀疏矩阵M1
    M.tu = 5;

    M.data = (Triple*)malloc(sizeof(Triple) * (M.tu + 1));
    if (NULL == M.data)
        return OVERFLOW;
    M.data[1].i = 1;
    M.data[1].j = 2;
    M.data[1].e = 14;

    M.data[2].i = 1;
    M.data[2].j = 5;
    M.data[2].e = -5;

    M.data[3].i = 2;
    M.data[3].j = 2;
    M.data[3].e = -7;

    M.data[4].i = 3;
    M.data[4].j = 1;
    M.data[4].e = 36;

    M.data[5].i = 3;
    M.data[5].j = 4;
    M.data[5].e = 28;

    M.mu = 3;
    M.nu = 5;

    return OK;
}

/*
3   0   1   5
0  -1   0   0
2   0   0   0

mu = 3; nu = 4; tu = 5
*/
Status CreateRLSMatrixM(RLSMatrix& M) { // 创建稀疏矩阵M
    M.tu = 5;

    M.data = (Triple*)malloc(sizeof(Triple) * (M.tu + 1));
    if (NULL == M.data)
        return OVERFLOW;
    M.data[1].i = 1;
    M.data[1].j = 1;
    M.data[1].e = 3;

    M.data[2].i = 1;
    M.data[2].j = 3;
    M.data[2].e = 1;

    M.data[3].i = 1;
    M.data[3].j = 4;
    M.data[3].e = 5;

    M.data[4].i = 2;
    M.data[4].j = 2;
    M.data[4].e = -1;

    M.data[5].i = 3;
    M.data[5].j = 1;
    M.data[5].e = 2;

    M.mu = 3;
    M.nu = 4;

    M.rpos = (int*)malloc((M.mu + 1) * sizeof(int));
    *(M.rpos + 1) = 1;
    *(M.rpos + 2) = 4;
    *(M.rpos + 3) = 5;

    return OK;
}

/*
0   2   6
1   0   0
-2  4   0
0   0   0

mu = 4; nu = 3; tu = 5
*/
Status CreateRLSMatrixK(RLSMatrix& M) { // 创建稀疏矩阵K
    M.tu = 5;

    M.data = (Triple*)malloc(sizeof(Triple) * (M.tu + 1));
    if (NULL == M.data)
        return OVERFLOW;
    M.data[1].i = 1;
    M.data[1].j = 2;
    M.data[1].e = 2;

    M.data[2].i = 1;
    M.data[2].j = 3;
    M.data[2].e = 6;

    M.data[3].i = 2;
    M.data[3].j = 1;
    M.data[3].e = 1;

    M.data[4].i = 3;
    M.data[4].j = 1;
    M.data[4].e = -2;

    M.data[5].i = 3;
    M.data[5].j = 2;
    M.data[5].e = 4;

    M.mu = 4;
    M.nu = 3;

    M.rpos = (int*)malloc((M.mu + 1) * sizeof(int));
    *(M.rpos + 1) = 1;
    *(M.rpos + 2) = 3;
    *(M.rpos + 3) = 4;
    *(M.rpos + 4) = 5;

    return OK;
}

int main() {     

   //矩阵转置
   TSMatrix M1;        
   TSMatrix M2;
   CreateSparseMatrixM1(M1);
   FastTransposeSMatrix(M1, M2);
   
   printf("\n");


   //其中M是3*4矩阵，有三元组： ((1, 1, 3), (1, 3, 1), (1, 4, 5), (2, 2, -1), (3, 1, 2))
   //    K是4*3矩阵，有三元组： ((1, 2, 2), (1, 3, 6), (2, 1, 1), (3, 1, -2), (3, 2, 4))
   RLSMatrix M;
   CreateRLSMatrixM(M);
   RLSMatrix K;
   CreateRLSMatrixK(K);


   //快速访问矩阵元素
   //1.1 预期结果：-1
   ElemType value_M = getValue(M, 2, 2);
   printf("%d\n", value_M);

   //1.2  预期结果：0
   ElemType value_K = getValue(K, 2, 2);
   printf("%d\n", value_K);

   //矩阵乘法。求P = M * K
   //预期结果：P是3*3矩阵，有三元组：((1, 1, -2), (1, 2, 10), (1, 3, 18), (2, 1, -1), (3, 2, 4), (3, 3, 12))
   RLSMatrix P;
   MultSMatrix(M, K, P);
   
   return 0;
}
