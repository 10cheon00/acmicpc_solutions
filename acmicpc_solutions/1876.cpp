/*
 * 1876 튕기는 볼링공
 * 실버III
 */
#include <cmath>
#include <iostream>
#define PI 3.14159265
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    double T, dist = 0;
    int X;
    scanf("%lf %d", &T, &X);
    double left = T * 100 - (16.0 / sin(PI * X / 180.0)),
           right = T * 100 + (16.0 / sin(PI * X / 180.0)),
           step = 85.0 / tan(PI * X / 180.0);
    while (dist < right) {
      if (left < dist && dist < right) {
        printf("yes\n");
        break;
      }
      dist += step;
    }
    if (dist >= right) {
      printf("no\n");
    }
  }
}