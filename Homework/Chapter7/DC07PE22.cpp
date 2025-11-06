#include "allinclude.h"  //DO NOT edit this line
int PTreeDepth(PTree T) {
    if (T.nodeNum == 0) {
        return 0;
    }

    int max_depth = 0;
    for (int i = 0; i < T.nodeNum; i++) {
        int current_depth = 1;
        int p = T.nodes[i].parent;
        while (p != -1) {
            current_depth++;
            p = T.nodes[p].parent;
        }
        if (current_depth > max_depth) {
            max_depth = current_depth;
        }
    }

    return max_depth;
}