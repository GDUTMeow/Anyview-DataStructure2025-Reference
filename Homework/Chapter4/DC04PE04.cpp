#include "allinclude.h"  //DO NOT edit this line

void PrintKeys(HashTable ht, void(*print)(StrKeyType))
{
    if (ht.rcd == NULL || ht.size == 0) {
        return;
    }

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        int hash_pos = (ch - 'A') % ht.size;

        for (int i = 0; i < ht.size; ++i) {
            int probe_pos = (hash_pos + i) % ht.size;

            if (ht.rcd[probe_pos].tag == 0) {
                break;
            }

            if (ht.rcd[probe_pos].tag == 1) {
                if (ht.rcd[probe_pos].key[0] == ch) {
                    print(ht.rcd[probe_pos].key);
                }
            }
        }
    }
}