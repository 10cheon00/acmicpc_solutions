/*
 * 3042 트리플렛
 * 실버III
 */
#include <iostream>
struct Point {
  int x, y;
};
int main() {
  char map[100][101];
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", map[i]);
  }
  int cnt = 0, size = 0;
  Point p[26];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (map[i][j] != '.') {
        p[size++] = {j, i};
      }
    }
  }
  for (int i = 0; i < size - 2; i++) {
    for (int j = i + 1; j < size - 1; j++) {
      for (int k = j + 1; k < size; k++) {
        if ((p[j].x - p[i].x) * (p[k].y - p[j].y) ==
            (p[j].y - p[i].y) * (p[k].x - p[j].x)) {
          cnt++;
        }
      }
    }
  }
  printf("%d", cnt);
}