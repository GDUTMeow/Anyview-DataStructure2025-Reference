#include "allinclude.h"
void printName(stuType student[], int index[], int n)
{  // Add your code here
    for (int i = 0; i < n; i++) {
        printf("%s\n", student[index[i]].name);
    }
}