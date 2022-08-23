/*
 * 10845 Å¥
 * ½Ç¹öIV
 */
#include <iostream>
#include <cstring>
#define isEqual(A, B) strcmp(A, B) == 0
int main()
{
    int N, queue[10001], front = 0, back = 0;
    scanf("%d", &N);
    char command[6];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", command);
        if (isEqual(command, "push"))
        {
            int num;
            scanf("%d", &num);
            queue[++back] = num;
        }
        if (isEqual(command, "pop"))
        {
            if (front == back)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", queue[front + 1]);
                queue[++front] = 0;
            }
        }
        if (isEqual(command, "size"))
        {
            printf("%d\n", back - front);
        }
        if (isEqual(command, "empty"))
        {
            printf("%d\n", back == front);
        }
        if (isEqual(command, "front"))
        {
            printf("%d\n", back == front ? -1 : queue[front + 1]);
        }
        if (isEqual(command, "back"))
        {
            printf("%d\n", back == front ? -1 : queue[back]);
        }
    }
}