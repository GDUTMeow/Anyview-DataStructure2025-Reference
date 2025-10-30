#include "allinclude.h"  //DO NOT edit this line

float Sqrt(float A, float p, float e)
{
    while (fabs(p * p - A) >= e) {
        p = (p + A / p) / 2;
    }
    return p;
}