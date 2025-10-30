#include "allinclude.h"  //DO NOT edit this line
int GListDepth(GList ls) 
{ // Add your code here
    int max_depth = 0;
    if (NULL == ls) {
        return 1;
    }
    if (ls -> tag == ATOM) {
        return 0;
    }
    GList ptr = ls;
    while (ptr != NULL) {
        int current_depth = GListDepth(ptr -> un.ptr.hp);
        if (current_depth > max_depth) {
            max_depth = current_depth;
        }
        ptr = ptr -> un.ptr.tp;
    }
    return max_depth + 1;
}