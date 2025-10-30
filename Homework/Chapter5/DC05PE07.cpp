#include "allinclude.h"  //DO NOT edit this line

int Akm(int m, int n)
{
    if (m < 0 || n < 0) {
        return -1;
    }

    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return Akm(m - 1, 1);
    } else {
        return Akm(m - 1, Akm(m, n - 1));
    }
}