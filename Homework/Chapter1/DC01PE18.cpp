#include "allinclude.h"  //DO NOT edit this line

int Factorial(int n) {
    if (n == 0) return 1;
    return n * Factorial(n - 1);
}

Status Series(int a[], int n) { 
    // Add your code here
    if (n == 0) return ERROR;
    for (int i = 0; i <= n; i++) {
        long long tmp = Factorial(i) * pow(2, i);
        if (tmp > MAXINT) return EOVERFLOW;
        a[i] = tmp;
    }
    return OK;
}