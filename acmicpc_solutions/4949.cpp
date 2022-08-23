#include <iostream>
#include <string>
using namespace std;
int main()
{
    while (1)
    {
        string str;
        char stack[101]{0}, size = 0, len = 0, i = 0;
        getline(cin, str);
        if (str[0] == '.')
        {
            return 0;
        }
        for (; str[i]; i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                stack[++size] = str[i];
            }
            if (str[i] == ')' || str[i] == ']')
            {
                if (size == 0)
                {
                    printf("no\n");
                    break;
                }
                if (stack[size] > 41 == str[i] > 41)
                {
                    stack[size--] = 0;
                }
                else
                {
                    printf("no\n");
                    break;
                }
            }
        }
        if (!str[i])
        {
            if (size)
            {
                printf("no\n");
            }
            else
            {
                printf("yes\n");
            }
        }
    }
}