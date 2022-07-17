/*
 * 2477 Âü¿Ü¹ç
 * ½Ç¹öIII
 */

#include <iostream>
#define RIGHT 1
#define LEFT 2
#define DOWN 3
#define UP 4

using namespace std;

int main() {
    int expectedNumberOfHarvestedMelon,
        directions[7],
        distances[7],
        yMax = 0,
        xMax = 0,
        innerY,
        innerX;

    cin >> expectedNumberOfHarvestedMelon;

    for (int i = 0; i < 6; ++i) {
        cin >> directions[i] >> distances[i];
    }
    directions[6] = directions[0];
    distances[6] = distances[0];

    for (int i = 0; i < 7; ++i) {
        if (directions[i] < DOWN) {
            if (xMax < distances[i]) {
                xMax = distances[i];
            }
        }
        else {
            if (yMax < distances[i]) {
                yMax = distances[i];
            }
        }

        if (i > 0) {
            if (directions[i - 1] == RIGHT && directions[i] == DOWN) {
                innerX = distances[i - 1];
                innerY = distances[i];
            }

            if (directions[i - 1] == UP && directions[i] == RIGHT) {
                innerY = distances[i - 1];
                innerX = distances[i];
            }

            if (directions[i - 1] == LEFT && directions[i] == UP) {
                innerX = distances[i - 1];
                innerY = distances[i];
            }

            if (directions[i - 1] == DOWN && directions[i] == LEFT) {
                innerY = distances[i - 1];
                innerX = distances[i];
            }
        }
    }

    cout << (xMax * yMax - innerX * innerY) * expectedNumberOfHarvestedMelon;
}