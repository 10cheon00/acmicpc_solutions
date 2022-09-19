/*
 * 2193 이친수
 * 실버III
1
10
100 101
1000 1010 1001
10000 10001 10100 10101 10010
100001 100000 100010 101000 101001 101010 100100 100101
*/
#include <iostream>
long long dp[91]{0, 1, 1};
long long f(int N) {
  if (!dp[N]) {
    dp[N] = f(N - 1) + f(N - 2);
  }
  return dp[N];
}
int main() {
  int N;
  scanf("%d", &N);
  printf("%lld", f(N));
}