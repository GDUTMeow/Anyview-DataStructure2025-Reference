#include "allinclude.h"  //DO NOT edit this line

Node* searchLHash(LHashTable H, KeyType key, int &c)
{
    c = 0;

    if (H.rcd == NULL || H.hash == NULL) {
        return NULL;
    }

    int addr = H.hash(key, H.size);
    Node* p = H.rcd[addr];

    while (p != NULL) {
        if (p->r.key == key) {
            return p;
        }
        c++;
        p = p->next;
    }

    return NULL;
}