#include <iostream>
#pragma warning(disable:4996)
#define RIGHT 0
#define BOTTOM 1
#define RIGHTBOTTOM 2
int N, arr[17][17]{ 0 }, dp[17][17]{ 0 };
void f(int y, int x, int dir) {
    if (x > N || y > N || arr[y][x]) {
        return;
    }
    if (dir == RIGHT) {
        dp[y][x]++;
        f(y, x + 1, RIGHT);
        f(y + 1, x + 1, RIGHTBOTTOM);
    }
    if (dir == BOTTOM) {
        dp[y][x]++;
        f(y + 1, x, BOTTOM);
        f(y + 1, x + 1, RIGHTBOTTOM);
    }
    if (dir == RIGHTBOTTOM && !(arr[y - 1][x] + arr[y][x - 1])) {
        dp[y][x]++;
        f(y, x + 1, RIGHT);
        f(y + 1, x + 1, RIGHTBOTTOM);
        f(y + 1, x, BOTTOM);
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    f(1, 2, RIGHT);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%3d", dp[i][j]);
        }
        puts("");
    }
    printf("%d", dp[N][N]);
}