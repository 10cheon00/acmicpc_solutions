/*
 * 6487 두 직선의 교차 여부
 * 실버II
 */
#include <iostream>
struct Point {
  int x, y;
};
struct Line {
  double a, b;
  bool isVertical;
};
Line calculateLineBetweenTwoPoint(Point p1, Point p2) {
  int de = p2.x - p1.x, nu = p2.y - p1.y;
  Line l;
  if (de == 0) {
    l.isVertical = true;
    l.b = p1.x;
  } else {
    l.isVertical = false;
    l.a = (double)nu / de;
    l.b = p1.y - l.a * p1.x;
  }
  return l;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    Point p[4];
    scanf("%d %d %d %d %d %d %d %d", &p[0].x, &p[0].y, &p[1].x, &p[1].y,
          &p[2].x, &p[2].y, &p[3].x, &p[3].y);

    Line l[2] = {calculateLineBetweenTwoPoint(p[1], p[0]),
                 calculateLineBetweenTwoPoint(p[3], p[2])};
    if (l[0].isVertical && l[1].isVertical) {
      printf("%s", l[0].b != l[1].b ? "NONE" : "LINE");
    } else if (l[0].isVertical || l[1].isVertical) {
      if (l[0].isVertical) {
        printf("POINT %.2f %.2f", l[0].b, l[1].a * l[0].b + l[1].b);
      } else {
        printf("POINT %.2f %.2f", l[1].b, l[0].a * l[1].b + l[0].b);
      }
    } else if (l[0].a != l[1].a) {
      printf("POINT %.2f %.2f", (l[1].b - l[0].b) / (l[0].a - l[1].a),
             (l[1].b - l[0].b) / (l[0].a - l[1].a) * l[0].a + l[0].b);
    } else if (l[0].b != l[1].b) {
      printf("NONE");
    } else {
      printf("LINE");
    }
    puts("");
  }
}