#include "allinclude.h"
int commonAncestor(SqBiTree T, int i, int j) {
    if (i <= 0 || i > T.lastIndex || j <= 0 || j > T.lastIndex) {
        return 0;
    }

    if (i == j) {
        return i / 2;
    }
    
    int temp_i = i;
    int temp_j = j;

    while (temp_i != temp_j) {
        if (temp_i > temp_j) {
            temp_i = temp_i / 2;
        } else {
            temp_j = temp_j / 2;
        }
    }

    if (temp_i == i || temp_i == j) {
        return 0;
    }

    return temp_i;
}