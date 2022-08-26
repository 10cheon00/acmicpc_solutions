/*
 * 16162 가희와 3단 고음
 * 실버IV
 */
#include <iostream>
int main() {
  int N, A, D;
  scanf("%d %d %d", &N, &A, &D);
  int K, C = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &K);
    if (K == A) {
      A += D;
      C++;
    }
  }
  printf("%d", C);
}