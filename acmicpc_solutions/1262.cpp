/*
 * 1262 알파벳 다이아몬드
 * 실버II
 */
#include <iostream>
#pragma warning(disable:4996)
#define ABS(X) (((X)>=0)?X:-(X))
int main() {
    int N, R1, C1, R2, C2;
    scanf("%d %d %d %d %d", &N, &R1, &C1, &R2, &C2);
    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j <= C2; j++) {
            int c = (ABS(N - j % (2 * N - 1) - 1) + ABS(N - i % (2 * N - 1) - 1));
            if (c < N)
                printf("%c", 'a' + c % 26);
            else
                printf(".");
        }
        puts("");
    }
}