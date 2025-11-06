#include "allinclude.h"  //DO NOT edit this line
int outDegree(ALGraph G, int k) {
    if (k < 0 || k >= G.n) {
        return -1;
    }

    int count = 0;
    AdjVexNodeP p = G.vexs[k].firstArc;

    while (p) {
        count++;
        p = p->next;
    }

    return count;
}