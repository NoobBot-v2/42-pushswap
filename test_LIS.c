#include <stdio.h>

void push()
{
    printf("push");
}

int LIS(int *s, int size, int offset)
{
    int i = 0;
    int length = 1;
    int last_max;
    i = i + offset;
    last_max = s[i];
    //size = 10 - 2 = 8
    //i = 7
    printf("--------------------\n");
    while (i < size - 2)
    {
        if (last_max < s[i])
        {
            printf("%-3i\n",last_max);
            last_max = s[i];
            length++;
        }
        else if (last_max < s[i + 1])
        {
            printf("%-3i\n",last_max);
            last_max = s[i + 1];
            length++;
        }
        i++;
    }
    printf("%-3i\n",last_max);
    printf("--------------------\n");
    return (length);
}

int main()
{

    int test[20] = {4, -2, 10, 5, -20,
                    0, 1, 28, -30, 6,
                    8, -100, -3, 43, 42,
                    1230, -432, 321, -1, 12};
    int size = 20;
    int i = 0;
    int length = 1;
    int longest_len = 1;
    int longest_i = 0;
    
    while (i < size)
    {
        length = LIS(test, size, i);
        if (length > longest_len)
        {
            longest_len = length;
            longest_i = i;
        }
        if (longest_len > (size - i))
            break ;
        i++;
    }
    printf("longest_len: %-3i\n",longest_len);
    printf("longest_start_idx: %-3i\n",longest_i);
    return 0;
}
