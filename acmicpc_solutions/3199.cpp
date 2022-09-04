/*
 * 3199 ABCD
 * 실버II
 */
#include <iostream>
int main() {
  double p, q, r;
  scanf("%lf %lf %lf", &p, &q, &r);
  if (p != r) {
    printf("0");
    return 0;
  }
  printf("%.4lf", p * (p + q) * 2);
}