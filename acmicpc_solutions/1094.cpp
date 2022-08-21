/*
 * 1094 막대기
 * 실버V
 */
#include <iostream>
#pragma warning(disable:4996)
int main() {
    int X, count = 0;
    scanf("%d", &X);
    while (X) {
        if (X % 2) {
            count++;
        }
        X /= 2;
    }
    printf("%d", count);
}