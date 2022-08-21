#include <iostream>
#pragma warning(disable:4996)
int main() {
    int N;
    scanf("%d", &N);
    int a, b, res = N, cnt = 0;

    do {
        a = res / 10;
        b = res % 10;
        res = b * 10 + (a + b) % 10;
        cnt++;
    } while (N != res);
    printf("%d", cnt);
}