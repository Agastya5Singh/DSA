#include <stdio.h>
#define size 20

void getData(int a[size][size], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void create(int a[size][size], int row, int column, int b[size][3])
{
    int k = 0;
    b[0][0] = row;
    b[0][1] = column;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
        b[0][2] = k;
    }
}

void display(int b[size][3])
{
    int column = b[0][2];
    printf("Row Column   Value\n");
    for (int i = 0; i < column; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

int main()
{
    int row, column;
    printf("Enter the row & columns of the source matrix: ");
    scanf("%d%d", &row, &column);

    int arr[row][column], arr2[size][3];

    getData(arr, row, column);
    create(arr, row, column, arr2);
    display(arr2);

    return 0;
}