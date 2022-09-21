#include <iostream>
int main() {
  int S, K;
  scanf("%d %d", &S, &K);
  long long res = 1;
  for (int i = 0; i < K - S % K; i++) {
    res *= S / K;
  }
  for (int i = 0; i < S % K; i++) {
    res *= S / K + 1;
  }
  printf("%lld", res);
}