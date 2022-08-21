/*
 * 1038 감소하는 수
 * 골드V
 */
#include <iostream>
#pragma warning(disable:4996)
int count = 9, N;
int arr[10]{ 0 };
void find(int num, int depth) {
    for (int i = 0; i < num; i++) {
        if (N <= count) {
            return;
        }
        arr[depth] = i;
        if (depth == 0) {
            count++;
        }
        else {
            find(i, depth - 1);
        }
    }
}

int main() {
    scanf("%d", &N);
    if (N < 10) {
        printf("%d", N);
        return 0;
    }
    for (int i = 1; i < 10; i++) {
        find(10, i);
        if (N == count) {
            for (int j = i; j >= 0; j--) {
                printf("%d", arr[j]);
            }
            return 0;
        }
    }
    printf("-1");
    return 0;
}