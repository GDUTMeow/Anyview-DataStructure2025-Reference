#include "allinclude.h"  //DO NOT edit this line
Status CreateUDG(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e) {
    if (n > MAX_VEX_NUM) {
        return ERROR;
    }

    G.n = n;
    G.e = e;
    G.kind = UDG;

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

        AdjVexNodeP node1 = new AdjVexNode;
        if (node1 == NULL) return ERROR;
        node1->adjvex = j;
        node1->info = arcs[k].inf;
        node1->next = G.vexs[i].firstArc;
        G.vexs[i].firstArc = node1;

        AdjVexNodeP node2 = new AdjVexNode;
        if (node2 == NULL) return ERROR;
        node2->adjvex = i;
        node2->info = arcs[k].inf;
        node2->next = G.vexs[j].firstArc;
        G.vexs[j].firstArc = node2;
    }

    return OK;
}