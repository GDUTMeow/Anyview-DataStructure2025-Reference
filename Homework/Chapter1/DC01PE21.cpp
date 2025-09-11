#include "allinclude.h"
float highestScore(stuType *student[], int n)
/* 返回最高成绩  */
{ // Add your code here
  float maxScore = student[0]->score;
  for (int i = 1; i < n; i++) {
    if (student[i]->score > maxScore) {
      maxScore = student[i]->score;
    }
  }
  return maxScore;
}