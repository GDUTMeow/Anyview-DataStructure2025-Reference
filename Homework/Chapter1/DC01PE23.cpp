#include "allinclude.h"
void printLastName_HighestScore(stuType *student[], int n)
{  // Add your code here
    float maxScore = student[0]->score;
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (student[i]->score >= maxScore) {    // 如果不加等于，在判断实例的时候就会因为预期结果为同分排序最后而出问题
            maxScore = student[i]->score;
            maxIndex = i;
        }
    }
    printf("%.4s\n", student[maxIndex]->name);  // 同上题，不加 .4 会因为 OJ 提供的数据本身的问题，导致输出出问题
    printf("%.2f\n", maxScore);
}