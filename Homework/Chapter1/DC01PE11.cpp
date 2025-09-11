#include "allinclude.h"  //DO NOT edit this line


Status Fibonacci(int k, int m, int &f) { 
    if (k < 2 || m < 0) {
        return ERROR;
    }

    if (m <= k - 2) {
        f = 0;
        return OK;
    }

    if (m == k - 1) {
        f = 1;
        return OK;
    }

    long long* fib_seq = new long long[m + 1];
    if (fib_seq == nullptr) {
        return ERROR;
    }

    for (int i = 0; i < k - 1; ++i) {
        fib_seq[i] = 0;
    }
    fib_seq[k - 1] = 1;

    long long current_sum = 1;

    for (int i = k; i <= m; ++i) {
        fib_seq[i] = current_sum;
        current_sum = current_sum + fib_seq[i] - fib_seq[i - k];
    }
    
    f = (int)fib_seq[m];
    
    delete[] fib_seq;
    
    return OK;
}