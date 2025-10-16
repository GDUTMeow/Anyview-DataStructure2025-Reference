#include "allinclude.h"  //DO NOT edit this line

/**
 * 求k阶斐波那契序列的第n+1项fn
 * @param k 阶数
 * @param n 序列中的位置
 * @return k阶斐波那契序列的第n+1项fn的值
 */
long Fib(int k, int n) { 
    // 如果n是初始项之一
    // f0=0, f1=0, ..., f(k-2)=0
    if (n < k - 1) {
        return 0;
    }
    // f(k-1)=1
    if (n == k - 1) {
        return 1;
    }

    // 使用循环队列存储最近的k个斐波那契数
    SqQueue Q;
    // 为队列分配k个元素的空间
    Q.base = (int *)malloc(k * sizeof(int));
    if (!Q.base) return EOVERFLOW; // 内存分配失败
    Q.front = 0;
    Q.rear = 0;
    Q.maxSize = k;

    // 初始化队列，填入序列的前k个初始值
    // f0 到 f(k-2) 均为 0
    for (int i = 0; i < k - 1; ++i) {
        Q.base[Q.rear] = 0;
        Q.rear = (Q.rear + 1) % Q.maxSize;
    }
    // f(k-1) 为 1
    Q.base[Q.rear] = 1;
    Q.rear = (Q.rear + 1) % Q.maxSize;

    // 变量 sum 存储队列中k个元素的和，也就是下一个斐波那契数的值
    // 初始时, sum = f0 + ... + f(k-1) = 1，即f(k)的值
    int sum = 1;
    int fn; // 用于存储最终结果f(n)

    // 从第k项开始循环计算到第n项
    for (int i = k; i <= n; ++i) {
        // 当前项 f(i) 是前面k项的和
        fn = sum;
        
        // 从队列中移除最旧的项，即 f(i-k)
        int oldest_term = Q.base[Q.front];
        Q.front = (Q.front + 1) % Q.maxSize;

        // 将新计算出的项 f(i) 加入队列
        Q.base[Q.rear] = fn;
        Q.rear = (Q.rear + 1) % Q.maxSize;

        // 更新sum，为计算下一项f(i+1)做准备
        // 新的和 = (旧的和) - (最旧的项) + (最新的项)
        sum = sum - oldest_term + fn;
    }

    // 释放为队列分配的内存
    free(Q.base);

    // 循环结束后, fn中保存的就是f(n)的值
    return fn;
}