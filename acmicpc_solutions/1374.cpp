/*
 * 1374 강의실
 * 골드V
 */
//시작 시간이 빠른 순부터
//같은 시작 시간일 경우 종료 시간이 빠른 순부터
//종료 시간이 제일 빠른 곳에 삽입
//종료 시간이 제일 빠른 곳을 찾기 위해 우선순위 큐를 사용
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
  int N, c;
  Lecture lec[100000];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &c, &lec[i].start, &lec[i].end);
  }
  sort(lec, lec + N, compare);
  priority_queue<int, vector<int>, greater<int>> room;
  room.push(0);
  for (int i = 0; i < N; i++) { // lec
    if (lec[i].start >= room.top()) {
      room.pop();
    }
    room.push(lec[i].end);
  }
  printf("%d", room.size());
}