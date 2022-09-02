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
    if (nextDownLeft < R)
      x = x <= N ? x + 1 : x;
    else if (nextDownLeft > R)
      y = y >= 0 ? y - 1 : y;
    else {
      x = x <= N ? x + 1 : x;
      y = y >= 0 ? y - 1 : y;
    }
    cnt++;
  }
  printf("%lld", cnt * 4);
}