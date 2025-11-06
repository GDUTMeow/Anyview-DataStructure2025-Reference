#include "allinclude.h"  //DO NOT edit this line
Status CreateDG(ALGraph &G, VexType *vexs, int n,
                            ArcInfo *arcs, int e) {
    if (n > MAX_VEX_NUM) {
        return ERROR;
    }

    G.n = n;
    G.e = e;
    G.kind = DG;

    for (int i = 0; i < n; i++) {
        G.vexs[i].data = vexs[i];
        G.vexs[i].firstArc = NULL;
    }

    for (int k = 0; k < e; k++) {
        VexType v1 = arcs[k].v;
        VexType v2 = arcs[k].w;

        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        if (i == -1 || j == -1) {
            return ERROR;
        }

        AdjVexNodeP newNode = new AdjVexNode;
        if (newNode == NULL) {
            return ERROR;
        }
        newNode->adjvex = j;
        newNode->info = arcs[k].inf;

        newNode->next = G.vexs[i].firstArc;
        G.vexs[i].firstArc = newNode;
    }

    return OK;
}