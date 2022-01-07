#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int Container[] = {1, 2, 3, 4, 5, 6, 7};
    int hunt = 5, i, j, l, n, Flag = 1;

    l = sizeof(Container) / sizeof(Container[0]);

    printf("\nInitial Hunt Value = %d", hunt);
    while (Flag == 1)
    {
        Flag = 0;
        for (i = 0; i < l; i++)
        {
            if (hunt == Container[i])
            {
                Flag = 1;
                hunt = hunt * 3;
            }
        }
    }
    printf("\nFinal Hunt Value = %d", hunt);
}