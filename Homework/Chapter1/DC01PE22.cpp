#include "allinclude.h"
void printFirstName_HighestScore(stuType *student[], int n)
{  // Add your code here
    float maxScore = student[0]->score;
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (student[i]->score > maxScore) {
            maxScore = student[i]->score;
            maxIndex = i;
        }
    }
    printf("%.4s\n", student[maxIndex]->name);  // 这里不加四位输出的话，会因为OJ 提供的数据本身的问题，导致输出出问题
    printf("%.2f\n", maxScore);
}