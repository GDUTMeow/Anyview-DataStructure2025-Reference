#include "allinclude.h"  //DO NOT edit this line
void Descend(int &a, int &b, int &c)  // 通过交换，令 a >= b >= c
{   // Add your code here
    if (a >= b) {
        ;
    } else {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (b >= c) {
        ;
    } else {
        int tmp = b;
        b = c;
        c = tmp;
    }
    if (a >= b) {
        ;
    } else {
        int tmp = a;
        a = b;
        b = tmp;
    }
}