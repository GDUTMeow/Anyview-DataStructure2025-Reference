#include "allinclude.h"
void countNodesAtLevel(BiTree T, int level, int* level_counts) {
    if (T == NULL) {
        return;
    }
    level_counts[level]++;
    countNodesAtLevel(T->lchild, level + 1, level_counts);
    countNodesAtLevel(T->rchild, level + 1, level_counts);
}

int treeHeight(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    int left_height = treeHeight(T->lchild);
    int right_height = treeHeight(T->rchild);
    return (left_height > right_height ? left_height : right_height) + 1;
}

int Width(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    
    int height = treeHeight(T);
    int* level_counts = new int[height];
    for (int i = 0; i < height; i++) {
        level_counts[i] = 0;
    }
    
    countNodesAtLevel(T, 0, level_counts);
    
    int max_width = 0;
    for (int i = 0; i < height; i++) {
        if (level_counts[i] > max_width) {
            max_width = level_counts[i];
        }
    }
    
    delete[] level_counts;
    return max_width;
}