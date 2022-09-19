/*
 * 15735 삼각
 * 실버III
 */
#include <iostream>
int main() {
  int N, key = 0;
  long long ans = 0;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    key += i;
    ans += key;
    if (i % 2 == (N - 1) % 2) {
      ans += key;
    }
  }
  printf("%lld", ans);
}