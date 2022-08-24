/*
 * 1720 타일 코드
 * 골드IV
 */
#include <iostream>
int dp[31]{1, 1}, symDp[31]{1, 1, 3, 1};
int f(int N) {
  if (!dp[N]) {
    dp[N] = f(N - 1) + f(N - 2) * 2;
  }
  return dp[N];
}
int symF(int N) {
  if (!symDp[N]) {
    symDp[N] = symF(N - 2) + symF(N - 4) * 2;
  }
  return symDp[N];
}
int main() {
  // 회전했을 때 중복되는 경우는 빼야한다.
  // 전체 경우에서 나누기 2를 한다면 중복인 경우가 사라질 것이다.
  // 하지만 1221처럼 한 가지 경우만 생기는 조합이 있으므로 이건 제외해야한다.
  // 2xN타일링3에서 얻은 개수에서 한 가지 경우만 생기는 개수를 빼고 나누기 2를
  // 한다. 그 다음 한 가지 경우만 생기는 경우를 더하면 답이다.
  int N;
  scanf("%d", &N);
  int sym = symF(N), num = f(N);
  printf("%d", (num - sym) / 2 + sym);
}
