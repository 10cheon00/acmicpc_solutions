/*
 * 1124 언더프라임
 * 실버II
 */

#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    int* primeSet = new int[B + 1]{ 0 };
    for (int i = 2; i <= B; i++)
    {
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                primeSet[i]++;
                if (primeSet[i / j])
                {
                    primeSet[i] = primeSet[i / j] + 1;
                }
                else {
                    primeSet[i]++;
                }
                break;
            }
        }
    }
    int count = 0;
    for (int i = A; i <= B; i++)
    {
        if (primeSet[i]) {
            if (primeSet[primeSet[i]] == 0)
            {
                count++;
            }
        }
    }
    printf("%d", count);
    delete[] primeSet;
    return 0;
}