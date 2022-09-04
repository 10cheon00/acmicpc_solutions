/*
 * 1709 타일 위의 원
 * 실버III
 */
#include <iostream>
#define LL long long
LL dist(LL x, LL y) { return x * x + y * y; }
int main() {
  LL N, x = 0, y, R, cnt = 0;
  scanf("%lld", &N);
  N /= 2;
  y = N - 1;
  R = N * N;
  while (x <= N && y >= 0) {
    LL nextDownLeft = dist(x + 1, y);
    if (nextDownLeft <= R)
      x++;
    if (nextDownLeft >= R)
      y--;
    cnt++;
  }
  printf("%lld", cnt * 4);
}