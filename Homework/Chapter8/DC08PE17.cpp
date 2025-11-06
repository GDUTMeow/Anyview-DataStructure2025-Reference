#include "allinclude.h"  //DO NOT edit this line
Status SetArc(MGraph &G, VexType v, VexType w, ArcCell info) {
    int i = LocateVex(G, v);
    int j = LocateVex(G, w);

    if (i == -1 || j == -1) {
        return ERROR;
    }

    if (i == j) {
        return ERROR;
    }

    G.arcs[i][j] = info;

    if (G.kind == UDG || G.kind == UDN) {
        G.arcs[j][i] = info;
    }

    return OK;
}