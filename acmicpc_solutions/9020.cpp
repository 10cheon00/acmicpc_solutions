/*
 * 9020 �������� ����
 * �ǹ�II
 */

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int length;
    cin >> length;
    int *numbers = new int[length];
    for (int i = 0; i < length; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = numbers[i] / 2; j >= 2; j--)
        {
            if (isPrime(j) && isPrime(numbers[i] - j))
            {
                cout << j << ' ' << numbers[i] - j << endl;
                break;
            }
        }
    }
    delete[] numbers;
}