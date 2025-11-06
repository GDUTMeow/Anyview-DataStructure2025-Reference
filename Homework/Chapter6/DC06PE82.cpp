#include "allinclude.h"  //DO NOT edit this line
void RightBalance(BBSTree &T) {
    BBSTree R, Rl;
    R = T->rchild;
    switch (R->bf) {
        case RH:
            T->bf = R->bf = EH;
            L_Rotate(T);
            break;
        case LH:
            Rl = R->lchild;
            switch (Rl->bf) {
                case RH:
                    T->bf = LH;
                    R->bf = EH;
                    break;
                case EH:
                    T->bf = R->bf = EH;
                    break;
                case LH:
                    T->bf = EH;
                    R->bf = RH;
                    break;
            }
            Rl->bf = EH;
            R_Rotate(T->rchild);
            L_Rotate(T);
            break;
    }
}