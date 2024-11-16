#include "stdio.h"
#include "stdlib.h"

int main()

{
    int N = 0;
    int counter = 1;

    printf("Enter N: ");
    scanf("%d",&N);

    int matrix[N][N];
    int Ibeg = 0, Ifin = 0, Jbeg = 0, Jfin = 0;

    int k = 1;
    int i = 0;
    int j = 0;

    while (k <= N * N)

    {
        matrix[i][j] = k;
        if (i == Ibeg && j < N - Jfin - 1)

            ++j;

        else if (j == N - Jfin - 1 && i < N - Ifin - 1)

            ++i;

        else if (i == N - Ifin - 1 && j > Jbeg)

            --j;

        else
            --i;

        if ((i == Ibeg + 1) && (j == Jbeg) && (Jbeg != N - Jfin - 1))

        {
            ++Ibeg;
            ++Ifin;
            ++Jbeg;
            ++Jfin;
        }
        ++k;
    }

    

    for (int i = 0; i < N; ++i){

        for (int j = 0; j < N; ++j)

            printf("%d", matrix[i][j]);

        printf("\n");
    }

}