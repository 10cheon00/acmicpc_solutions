/*
 * 1485 정사각형
 * 실버III
 */
#include <iostream>
struct Point {
  int x, y;
};
long long dot(Point vec1, Point vec2) {
  return (long long)vec1.x * vec2.x + (long long)vec1.y * vec2.y;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    Point p[4];
    for (int j = 0; j < 4; j++) {
      scanf("%d%d", &p[j].x, &p[j].y);
    }
    for (int j = 0; j < 3; j++) {
      for (int k = j + 1; k < 4; k++) {
        if (p[j].x > p[k].x || (p[j].x == p[k].x && p[j].y > p[k].y)) {
          Point t = p[j];
          p[j] = p[k];
          p[k] = t;
        }
      }
    }
    Point d1 = {p[3].x - p[0].x, p[3].y - p[0].y},
          d2 = {p[2].x - p[1].x, p[2].y - p[1].y};

    printf("%d\n", dot(d1, d2) == 0 && dot(d1, d1) == dot(d2, d2));
  }
}