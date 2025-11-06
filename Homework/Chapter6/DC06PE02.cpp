#include "allinclude.h"
Status is_Desendant(SqBiTree T, int u, int v) {
    if (u <= 0 || v <= 0 || u > T.lastIndex || v > T.lastIndex || u >= v) {
        return FALSE;
    }

    while (v > u) {
        v = v / 2;
    }

    if (v == u) {
        return TRUE;
    }

    return FALSE;
}