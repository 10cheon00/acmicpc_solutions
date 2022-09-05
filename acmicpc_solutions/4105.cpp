/*
 * 4105 유클리드
 * 실버II
 */
#include <cmath>
#include <iostream>
#define ABS(X) ((X) > 0 ? (X) : -(X))
struct Point {
  double x, y;
};
double d(Point p1, Point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
bool isZero(Point p1) { return p1.x == 0 && p1.y == 0; }
int main() {
  Point A, B, C, D, E, F;
  while (1) {
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x,
          &B.y, &C.x, &C.y, &D.x, &D.y, &E.x, &E.y, &F.x, &F.y);
    if (isZero(A) && isZero(B) && isZero(C) && isZero(D) && isZero(E) &&
        isZero(F)) {
      return 0;
    }
    double DE = d(D, E), EF = d(E, F), FD = d(F, D), s = (DE + EF + FD) / 2,
           DEF = sqrt(s * (s - DE) * (s - EF) * (s - FD));
    Point ABvec = {B.x - A.x, B.y - A.y}, ACvec = {C.x - A.x, C.y - A.y};
    double cosTheta =
               ABS(ABvec.x * ACvec.x + ABvec.y * ACvec.y) / (d(A, B) * d(A, C)),
           sinTheta = sqrt(1.0 - pow(cosTheta, 2)),
           AH = DEF / (d(A, B) * sinTheta);
    Point H = {A.x + (C.x - A.x) * (AH / d(A, C)),
               A.y + (C.y - A.y) * (AH / d(A, C))},
          G = {H.x + B.x - A.x, H.y + B.y - A.y};
    printf("%.3lf %.3lf %.3lf %.3lf\n", G.x, G.y, H.x, H.y);
  }
}