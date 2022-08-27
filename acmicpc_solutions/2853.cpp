/*
 * 2853 배
 * 실버I
 */
#include <iostream>
#include <queue>
using namespace std;

struct Ship {
  int nextVisitDay, interval;
  Ship(int n, int i) : nextVisitDay(n), interval(i) {}
};

struct Cmp {
  bool operator()(Ship &s1, Ship &s2) {
    return s1.nextVisitDay > s2.nextVisitDay;
  }
};

int main() {
  int N, num;
  scanf("%d", &N);
  scanf("%d", &num);
  priority_queue<Ship, vector<Ship>, Cmp> arr;
  for (int i = 1; i < N; i++) {
    scanf("%d", &num);
    bool isNotVisited = true;
    if (arr.size()) {
      while (num == arr.top().nextVisitDay) {
        Ship s(arr.top());
        s.nextVisitDay += s.interval;
        arr.pop();
        arr.push(s);
        isNotVisited = false;
      }
    }
    if (isNotVisited) {
      Ship s(2 * num - 1, num - 1);
      arr.push(s);
    }
  }
  printf("%d", arr.size());
}
// 1 7 10 13 19
//   6  9 12 18
// 1 3 4 5 7 8 9 10
//   2   4 6   8
//     3   6      9
//           7
/*

8
1
3
4
5
7
8
9
10
*/