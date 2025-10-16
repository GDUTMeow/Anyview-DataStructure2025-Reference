#include "allinclude.h"
Status matchBracketSequence(char* exp, int n)
{  // Add your code here
    SqStack S;
    InitStack_Sq(S, MAXSIZE, INCREMENT);
    for (int i = 0; i < n; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            Push_Sq(S, exp[i]);        
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (StackEmpty_Sq(S)) {
                return ERROR;
            } else {
                ElemType ch;
                Pop_Sq(S, ch);
                if ((ch == '(' && exp[i] != ')') || (ch == '[' && exp[i] != ']') || (ch == '{' && exp[i] != '}')) {
                    return ERROR;
                }
            }
        }
    }
    if (!StackEmpty_Sq(S)) {
        return ERROR;
    }
    return OK;
}