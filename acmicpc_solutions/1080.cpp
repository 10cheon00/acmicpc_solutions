/*
 * 1080 행렬
 * 실버I
 */
#include <iostream>
#pragma warning(disable:4996)
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    char** A = new char* [N];
    char** B = new char* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new char[M + 1];
        B[i] = new char[M + 1];
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%s", A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%s", B[i]);
        for (int j = 0; j < M; j++) {
            A[i][j] = A[i][j] != B[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] && i + 2 < N && j + 2 < M)
            {
                count++;
                A[i][j] = !A[i][j];
                A[i][j + 1] = !A[i][j + 1];
                A[i][j + 2] = !A[i][j + 2];
                A[i + 1][j] = !A[i + 1][j];
                A[i + 1][j + 1] = !A[i + 1][j + 1];
                A[i + 1][j + 2] = !A[i + 1][j + 2];
                A[i + 2][j] = !A[i + 2][j];
                A[i + 2][j + 1] = !A[i + 2][j + 1];
                A[i + 2][j + 2] = !A[i + 2][j + 2];
            }
            if (A[i][j])
            {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", count);

    for (int i = 0; i < N; i++)
    {
        delete[] A[i];
        delete[] B[i];
    }
    delete[] A;
    delete[] B;
}