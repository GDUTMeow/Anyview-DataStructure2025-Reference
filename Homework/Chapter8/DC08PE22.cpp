#include "allinclude.h"  //DO NOT edit this line
int inDegree(ALGraph G, int k) {
    if (k < 0 || k >= G.n) {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < G.n; i++) {
        AdjVexNodeP p = G.vexs[i].firstArc;
        while (p) {
            if (p->adjvex == k) {
                count++;
            }
            p = p->next;
        }
    }

    return count;
}