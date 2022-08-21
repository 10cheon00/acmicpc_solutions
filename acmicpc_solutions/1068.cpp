/*
 * 1068 트리
 * 골드V
 */
#include <iostream>
#pragma warning(disable:4996)
int arr[50]{ 0 }, N, count[50]{ 0, };
void deleteNode(int index) {
    arr[index] = -2;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == index) {
            // index 하위의 노드 탐색
            deleteNode(i);
        }
    }
}
int countNodes() {
    int num = 0;
    std::fill_n(count, 50, 1);
    for (int i = 0; i < N; i++) {
        if (arr[i] > -1) {
            count[arr[i]] = 0;
        }
        else if (arr[i] == -2) {
            count[i] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        if (count[i] && arr[i] != -2) {
            num++;
        }
    }
    return num;
}
int main() {
    int index;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &index);
    deleteNode(index);
    printf("%d", countNodes());
}