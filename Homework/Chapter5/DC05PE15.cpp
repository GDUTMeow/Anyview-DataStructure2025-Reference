#include "allinclude.h"  //DO NOT edit this line

int F(int n)
{
    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 1;
    }

    int product = 1;
    while (n > 0) {
        product *= n;
        n /= 2;
    }
    return product;
}