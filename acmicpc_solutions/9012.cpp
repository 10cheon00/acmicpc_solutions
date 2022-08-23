/*
 * 9012 °ıÈ£
 * ½Ç¹öIV
 */
#include <iostream>
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char str[51], j = 0, size = 0;
        bool hasError = false;
        scanf("%s", str);
        while (str[j])
        {
            if (str[j] == '(')
            {
                size++;
            }
            if (str[j] == ')')
            {
                if (size)
                {
                    size--;
                }
                else
                {
                    hasError = true;
                    break;
                }
            }
            j++;
        }
        if (!str[j] && size)
        {
            hasError = true;
        }

        if (hasError)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}