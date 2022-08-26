/*
 * 1092 배
 * 골드V
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N, M, c[50];

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &c[i]);
  }
  sort(c, c + N, greater<int>());

  vector<int> w;
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    int t;
    scanf("%d", &t);
    if (c[0] < t) {
      printf("-1");
      return 0;
    }
    w.push_back(t);
  }
  sort(w.begin(), w.end(), greater<int>());
  int boxes = 0, count = 0;
  while (1) {
    count++;
    for (int i = 0; i < N; i++) {
      for (auto iter = w.begin(); iter != w.end(); iter++) {
        if (c[i] >= *iter) {
          w.erase(iter);
          boxes++;
          break;
        }
      }
      if (boxes == M) {
        printf("%d", count);
        return 0;
      }
    }
  }
}
