#include <iostream>
#pragma warning(disable:4996)
int main() {
    int N, M, count[26]{ 0 };
    scanf("%d %d", &N, &M);
    char** arr = new char*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[M + 1];
        scanf("%s", arr[i]);
    }

    int x = 1, y = 1;
    for (int i = 0; i < N*M; i++) { // 크기변경
        if (x < M) {
            x++;
        }
        else {
            x = 1;
            if (y < N) {
                y++;
            }
        }
        for (int j = 0; j < N; j++) { // 세로이동
            for (int k = 0; k < M; k++) { // 가로이동
                count[arr[j][k] - 'A'] += (x + M) * (y + N);
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%d\n", count[i]);
    }

    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}