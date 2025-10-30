#include "allinclude.h"  //DO NOT edit this line

int countConflics(LHashTable H)
{
    int conflicts = 0;
    
    if (H.rcd == NULL || H.size <= 0) {
        return 0;
    }

    for (int i = 0; i < H.size; i++) {
        Node* p = H.rcd[i];
        
        if (p != NULL) {
            p = p->next;
            while (p != NULL) {
                conflicts++;
                p = p->next;
            }
        }
    }
    
    return conflicts;
}