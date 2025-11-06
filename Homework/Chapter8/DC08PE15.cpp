#include "allinclude.h"  //DO NOT edit this line
int NextAdjVex(MGraph G, int k, int m) {
    for (int j = m + 1; j < G.n; j++) {
        if (G.kind == DN || G.kind == UDN) {
            if (G.arcs[k][j].adj != INFINITY) {
                return j;
            }
        } else {
            if (G.arcs[k][j].adj == 1) {
                return j;
            }
        }
    }
    return -1;
}