/*
 * 1018 체스판 다시 칠하기
 * 실버IV
 */

#include <iostream>

using namespace std;

int main() {
    int x, y, whiteStartCount = 0, blackStartCount = 0, min = 64;
    cin >> y >> x;

    char** board = new char* [y];
    for (int i = 0; i < y; i++) {
        board[i] = new char[x + 1];
        cin >> board[i];
    }

    for (int i = 0; i <= y - 8; i++) {
        for (int j = 0; j <= x - 8; j++) {
            char tile = 'W';
            whiteStartCount = 0;
            blackStartCount = 0;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (tile == board[i + k][j + l]) {
                        whiteStartCount++;
                    }
                    if (tile != board[i + k][j + l]) {
                        blackStartCount++;
                    }
                    if (l < 7) {
                        if (tile == 'B') {
                            tile = 'W';
                        }
                        else {
                            tile = 'B';
                        }
                    }
                }
            }
            if (whiteStartCount < min) {
                min = whiteStartCount;
            }
            if (blackStartCount < min) {
                min = blackStartCount;
            }
        }
    }

    cout << min;

    for (int i = 0; i < y; i++) {
        delete[] board[i];
    }
    delete[] board;
}