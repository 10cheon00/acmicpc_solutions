/*
 * 18187 평면 분할
 * 실버II
 */
#include <iostream>
int main() {
  int N, lines[3]{0}, areaCount = 1;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    areaCount += 1 + lines[0] + lines[1] + lines[2] - lines[i % 3]++;
  }
  printf("%d", areaCount);
}