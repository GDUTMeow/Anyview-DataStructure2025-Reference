#include "allinclude.h"  //DO NOT edit this line

float Sqrt(float A, float p, float e)
{
    if (fabs(p * p - A) < e) {
        return p;
    } else {
        return Sqrt(A, (p + A / p) / 2, e);
    }
}