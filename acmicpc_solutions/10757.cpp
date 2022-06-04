/*
 * 10757 큰 수 A+B
 * 브론즈V
 */

#include <iostream>
#define aToi(X) (X - '0')
#define iToa(X) (X + '0')

using namespace std;

int main() {
    char a[10002] = { 0, }, b[10002] = { 0, }, result[10003] = { 0, };
    int aLength = 0, bLength = 0, carry = 0;

    cin >> a >> b;

    while (a[++aLength]);
    while (b[++bLength]);

    for (int i = 0;; i++) {
        if (i < aLength) {
            carry += aToi(a[aLength - 1 - i]);
        }
        if (i < bLength) {
            carry += aToi(b[bLength - 1 - i]);
        }
        result[i] = iToa(carry % 10);
        carry /= 10;
        if (i >= aLength - 1 && i >= bLength - 1 && carry == 0) {
            break;
        }
    }

    for (int i = 10002; i >= 0; i--) {
        if (result[i] != '\0') {
            cout << result[i];
        }
    }
}