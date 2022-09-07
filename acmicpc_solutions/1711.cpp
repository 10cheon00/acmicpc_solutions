/*
 * 1711 직각삼각형
 * 실버I
 * */
#include <iostream>
struct Point {
  long long x, y;
};
int dot(Point p1, Point p2) { return (p1.x * p2.x + p1.y * p2.y) == 0; }
Point getVec(Point p1, Point p2) {
  Point p = {p1.x - p2.x, p1.y - p2.y};
  return p;
}
int main() {
  int N;
  scanf("%d", &N);
  Point p[1500]{0};
  for (int i = 0; i < N; i++) {
    scanf("%lld %lld", &p[i].x, &p[i].y);
  }
  int cnt = 0;
  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      for (int k = j + 1; k < N; k++) {
        Point vec1 = getVec(p[i], p[j]), vec2 = getVec(p[j], p[k]),
              vec3 = getVec(p[k], p[i]);
        if (dot(vec1, vec2) + dot(vec2, vec3) + dot(vec3, vec1) == 1) {
          cnt++;
        }
      }
    }
  }
  printf("%d", cnt);
}