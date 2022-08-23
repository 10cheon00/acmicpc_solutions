/*
 * 10866 µ¦
 * ½Ç¹öIV
 */
#include <iostream>
#include <cstring>
#define isEqual(A, B) strcmp(A, B) == 0
int main()
{
    int N, size = 0, deque[20001], front = 10000, back = 10000;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        char cmd[11];
        scanf("%s", cmd);
        if (isEqual(cmd, "push_back"))
        {
            scanf("%d", &deque[++back]);
        }
        if (isEqual(cmd, "push_front"))
        {
            scanf("%d", &deque[front--]);
        }
        if (isEqual(cmd, "pop_front"))
        {
            printf("%d\n", front == back ? -1 : deque[++front]);
        }
        if (isEqual(cmd, "pop_back"))
        {
            printf("%d\n", front == back ? -1 : deque[back--]);
        }
        if (isEqual(cmd, "size"))
        {
            printf("%d\n", back - front);
        }
        if (isEqual(cmd, "empty"))
        {
            printf("%d\n", back == front);
        }
        if (isEqual(cmd, "front"))
        {
            printf("%d\n", back == front ? -1 : deque[front + 1]);
        }
        if (isEqual(cmd, "back"))
        {
            printf("%d\n", back == front ? -1 : deque[back]);
        }
    }
}