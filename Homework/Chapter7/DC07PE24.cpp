#include "allinclude.h"  //DO NOT edit this line
int PCTreeDepth(PCTree T) {
    if (T.n == 0) {
        return 0;
    }

    int max_depth = 0;
    int* depths = new int[T.n];
    for (int i = 0; i < T.n; i++) {
        depths[i] = 0;
    }

    for (int i = 0; i < T.n; i++) {
        int current_depth = 0;
        int j = i;
        while (j != -1 && depths[j] == 0) {
            j = T.nodes[j].parent;
        }

        if (j != -1) {
            current_depth = depths[j];
        }
        
        j = i;
        while (j != -1 && depths[j] == 0) {
            depths[j] = current_depth--;
            j = T.nodes[j].parent;
        }
        
        j = i;
        current_depth = 1;
        int p = T.nodes[j].parent;
        while(p != -1){
            current_depth++;
            p = T.nodes[p].parent;
        }

        if (current_depth > max_depth) {
            max_depth = current_depth;
        }
    }
    
    delete[] depths;
    return max_depth;
}