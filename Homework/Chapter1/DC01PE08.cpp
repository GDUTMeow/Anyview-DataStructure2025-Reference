#include "allinclude.h"                      //DO NOT edit this line
float Polynomial(int n, int a[], float x0) { // Add your code here
  float result = 0.0;
  for (int i = 0; i <= n; i++) {
    result += (a[i] * pow(x0, i));
  }
  return result;
}