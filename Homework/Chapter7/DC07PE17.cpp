#include "allinclude.h"

int Degree(CSTree T) {
    if (T == NULL) {
        return 0;
    }

    int root_degree = 0;
    CSTree child = T->firstChild;
    while (child) {
        root_degree++;
        child = child->nextSibling;
    }

    int max_child_subtree_degree = 0;
    child = T->firstChild;
    while (child) {
        int current_child_subtree_degree = Degree(child);
        if (current_child_subtree_degree > max_child_subtree_degree) {
            max_child_subtree_degree = current_child_subtree_degree;
        }
        child = child->nextSibling;
    }

    if (root_degree > max_child_subtree_degree) {
        return root_degree;
    } else {
        return max_child_subtree_degree;
    }
}