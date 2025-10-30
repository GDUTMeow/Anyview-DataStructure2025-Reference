#include "allinclude.h"  //DO NOT edit this line

void CountSort(RcdSqList2 &L)
{
    if (L.length <= 1) {
        return;
    }

    int n = L.length;
    int c[MAXSIZE + 1];
    RcdSqList2 temp_L;

    for (int i = 1; i <= n; ++i) {
        c[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (L.rcd[j].key < L.rcd[i].key) {
                c[i]++;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        temp_L.rcd[c[i] + 1] = L.rcd[i];
    }

    for (int i = 1; i <= n; ++i) {
        L.rcd[i] = temp_L.rcd[i];
    }
}