#include "allinclude.h"

StrSequence* reverseStr(StrSequence* strSeq)
{
    StrSequence* reversedSeq = (StrSequence*)malloc(sizeof(StrSequence));
    if (reversedSeq == NULL) {
        return NULL; 
    }

    reversedSeq->length = strSeq->length;
    reversedSeq->elem = (ElemType*)malloc((reversedSeq->length + 1) * sizeof(ElemType));

    if (reversedSeq->elem == NULL) {
        free(reversedSeq);
        return NULL;
    }

    for (int i = 0; i < reversedSeq->length; i++) {
        reversedSeq->elem[i] = strSeq->elem[reversedSeq->length - 1 - i];
    }

    reversedSeq->elem[reversedSeq->length] = '\0';

    return reversedSeq;
}