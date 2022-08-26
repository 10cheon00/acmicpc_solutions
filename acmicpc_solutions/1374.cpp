#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Lecture {
  int start, end;
};
bool compare(Lecture &l1, Lecture &l2) {
  if (l1.start == l2.start) {
    return l1.end < l2.end;
  }
  return l1.start < l2.start;
}
int main() {
  int N, c, size = 1, room[100001]{0};
  Lecture lec[100000];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &c, &lec[i].start, &lec[i].end);
  }
  std::sort(lec, lec + N, compare);

  for (int i = 0; i < N; i++) { // lec
    int j = 1;
    for (; j <= size; j++) { // room
      if (room[j] <= lec[i].start) {
        room[j] = lec[i].end;
        break;
      }
    }
    if (j > size) {
      room[++size] = lec[i].end;
    }
  }
  printf("%d", size);
}
/*
시작 시간이 빠른 순부터
같은 시작 시간일 경우 종료 시간이 빠른 순부터
01   5    1         2
  +------------
   +-----
      +--------------
      +---------------------
       +------
            +------
                +-----
                    +-----


10
10 15 20
2 0 5
3 5 7
1 0 4
8 12 15
4 5 9
7 10 11
5 7 12
6 9 12
9 12 17
*/