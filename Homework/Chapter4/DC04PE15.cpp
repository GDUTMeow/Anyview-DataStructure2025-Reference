#include "allinclude.h"  //DO NOT edit this line

int BuildHashTab(ChainHashTab &H, int n, HKeyType es[])
{
    HLink p, s;
    int addr;

    for (int i = 0; i < n; i++) {
        addr = Hash(H, es[i]);
        p = H.rcd[addr];

        while (p != NULL && p->data != es[i]) {
            p = p->next;
        }

        if (p == NULL) {
            s = (HLink)malloc(sizeof(HNode));
            if (!s) exit(EOVERFLOW);

            s->data = es[i];
            s->next = H.rcd[addr];
            H.rcd[addr] = s;
            
            H.count++;
        }
    }

    return H.count;
}