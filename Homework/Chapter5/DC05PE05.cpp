#include "allinclude.h"  //DO NOT edit this line

int F(int n)
{
    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return n + 1;
    } else {
        return n * F(n / 2);
    }
}