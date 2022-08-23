/*
 * 10994 별 찍기 - 19
 * 실버IV
 */
#include <iostream>
#define ABS(X) ((X) > 0 ? (X) : -(X))
int main() {
  int N;
  scanf("%d", &N);
  int center = 2 * N - 2;
  for (int i = 0; i <= 4 * N - 3; i++) {
    for (int j = 0; j <= 4 * N - 3; j++) {
      char ch = ' ';
      for (int k = N; k >= 0; k--) {
        int dist = 2 * k;
        int dx = ABS(j - center), dy = ABS(i - center);
        if (dx + dy <= 2 * dist && (dx == dist || dy == dist)) {
          ch = '*';
          break;
        }
      }
      printf("%c", ch);
    }
    puts("");
  }
}