#include "allinclude.h"

void tree_to_string_builder(BiTree T, char*& current_pos) {
    *current_pos++ = T->data;

    if (T->lchild == NULL && T->rchild == NULL) {
        return;
    }

    *current_pos++ = '(';

    if (T->lchild) {
        tree_to_string_builder(T->lchild, current_pos);
    } else {
        *current_pos++ = '#';
    }

    *current_pos++ = ',';

    if (T->rchild) {
        tree_to_string_builder(T->rchild, current_pos);
    } else {
        *current_pos++ = '#';
    }

    *current_pos++ = ')';
}

int get_required_size(BiTree T) {
    if (T == NULL) {
        return 0;
    }

    int size = 1;

    if (T->lchild == NULL && T->rchild == NULL) {
        return size;
    }

    size += 3;
    size += (T->lchild ? get_required_size(T->lchild) : 1);
    size += (T->rchild ? get_required_size(T->rchild) : 1);

    return size;
}

char* BiTree2String(BiTree T) {
    if (T == NULL) {
        char* result = new char[2];
        result[0] = '#';
        result[1] = '\0';
        return result;
    }

    int size = get_required_size(T);
    char* buffer = new char[size + 1];
    char* p = buffer;

    tree_to_string_builder(T, p);
    *p = '\0';

    return buffer;
}