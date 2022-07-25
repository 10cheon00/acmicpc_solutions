/*
 * 1283 단축키지정
 * 실버II
 */
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
#define UPPER(X) (((X)>'Z')?(X - 32):(X))
#define charToIndex(X) (UPPER(X) - 'A')
int main() {
    int N;
    char str[55];
    bool sc[26]{ false };
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int q[50]{ -1 }, size = 0, len = 0;
        scanf("%c", &str[0]);
        scanf("%[^\n]", str);
        while (str[len]) len++;
        q[size++] = 0;
        for (int j = 1; str[j]; j++) {
            if (str[j - 1] == ' ') {
                q[size++] = j;
            }
        }
        for (int j = 1; str[j]; j++) {
            if (str[j] != ' ') {
                int k = 0;
                while (k < size) {
                    if (q[k] == j) {
                        break;
                    }
                    k++;
                }
                if (k == size) {
                    q[size++] = j;
                }
            }
        }
        int index = 0;
        for (int j = 0; j < len; j++) {
            int atoi = charToIndex(str[q[j]]);
            if (sc[atoi] == false) {
                sc[atoi] = true;
            }
        }

        for (int j = 0; j < len; j++) {
            if (j == index) {
                printf("[%c]", str[j]);
            }
            else {
                printf("%c", str[j]);
            }
        }
        puts("");
    }
}