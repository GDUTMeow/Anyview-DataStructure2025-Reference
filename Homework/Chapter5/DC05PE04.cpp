#include "allinclude.h"  //DO NOT edit this line

int G(int m, int n) 
{
    if (m < 0 || n < 0) {
        return -1;
    }

    if (m == 0) {
        return 0;
    } 
    else {
        return G(m - 1, 2 * n) + n;
    }
}