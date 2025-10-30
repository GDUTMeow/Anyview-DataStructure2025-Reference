#include "allinclude.h"  //DO NOT edit this line

void BubbleSort(RcdSqList2 &L)
{
    int last_exchange_pos = L.length;

    while (last_exchange_pos > 1) {
        int current_pass_last_swap = 0;

        for (int j = 1; j < last_exchange_pos; ++j) {
            if (GT(L.rcd[j], L.rcd[j + 1])) {
                Swap(L.rcd[j], L.rcd[j + 1]);
                current_pass_last_swap = j;
            }
        }
        
        last_exchange_pos = current_pass_last_swap;
    }
}