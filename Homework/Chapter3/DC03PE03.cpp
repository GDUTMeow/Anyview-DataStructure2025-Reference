#include "allinclude.h"  //DO NOT edit this line

void InsertSort(RcdSqList &L)
{
    int i, j;
    for (i = 2; i <= L.length; ++i) {
        if (L.rcd[i].key < L.rcd[i-1].key) {
            L.rcd[0] = L.rcd[i]; 
            for (j = i - 1; L.rcd[0].key < L.rcd[j].key; --j) {
                L.rcd[j + 1] = L.rcd[j];
            }
            L.rcd[j + 1] = L.rcd[0];
        }
    }
}