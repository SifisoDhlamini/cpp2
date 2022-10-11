#include <stdio.h>
#include <stdbool.h>
int main()
{

    int num;
    scanf("%d", &num);
    while (num != 0)
    {
        int sum = num;
        int factor;
        if (num > 3)
        {
            factor = 2;
            while (factor <= sum && factor != num)
            {
                bool isPrime = true;
                if (sum % factor == 0)
                {
                    int prime = 2;
                    for (; prime <= factor / 2; prime++)
                    {
                        if (factor % prime == 0)
                        {
                            isPrime = false;
                        }
                    }
                    if (isPrime)
                    {
                        while (sum % factor == 0)
                        {
                            if (sum == num)
                            {
                                printf("%d = %d", sum, factor);
                            }
                            else
                            {
                                printf(" * %d", factor);
                            }
                            sum /= factor;
                        }
                    }
                }
                factor++;
            }
        }
        if (sum == 1)
            printf("\n");
        scanf("%d", &num);
    }

    return 0;
}