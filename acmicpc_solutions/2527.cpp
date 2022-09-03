/*
 * 2527 직사각형
 * 실버II
 */
#include <iostream>
struct Rect {
  int bottom, left, top, right;
};
int main() {
  Rect r1, r2;
  while (scanf("%d %d %d %d %d %d %d %d", &r1.left, &r1.bottom, &r1.right,
               &r1.top, &r2.left, &r2.bottom, &r2.right, &r2.top) != EOF) {
    if (r1.top < r2.bottom || r1.bottom > r2.top || r1.right < r2.left ||
        r1.left > r2.right) {
      printf("d");
    } else {
      int equalCoordsCount = (r1.top == r2.bottom) + (r1.bottom == r2.top) +
                             (r1.right == r2.left) + (r1.left == r2.right);
      printf("%c", equalCoordsCount == 0   ? 'a'
                   : equalCoordsCount == 1 ? 'b'
                                           : 'c');
    }
    puts("");
  }
}