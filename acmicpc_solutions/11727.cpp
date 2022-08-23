/*
 * 2xN 타일링3
 * 실버III
 */
#include <iostream>
int dp[1001]{1, 1};
int f(int N) {
  if (!dp[N]) {
    dp[N] = (f(N - 1) + f(N - 2) + f(N - 2)) % 10007;
  }
  return dp[N];
}
int main() {
  int N;
  scanf("%d", &N);
  printf("%d", f(N));
}