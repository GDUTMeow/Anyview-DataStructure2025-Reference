#include "allinclude.h"  //DO NOT edit this line
Status CreateDG(MGraph &G, VexType *vexs, int n,
                           ArcInfo *arcs, int e) {
    if (InitGraph(G, DG, n) != OK) {
        return ERROR;
    }

    G.n = n;
    G.e = e;

    for (int i = 0; i < n; i++) {
        G.vexs[i] = vexs[i];
    }

    for (int k = 0; k < e; k++) {
        VexType v1 = arcs[k].v;
        VexType v2 = arcs[k].w;

        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        if (i == -1 || j == -1) {
            return ERROR;
        }

        G.arcs[i][j].adj = 1;
    }

    return OK;
}