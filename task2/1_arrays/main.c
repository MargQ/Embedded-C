#include <stdio.h>

int main() {
    int N;

    // Ввод размера матрицы
    printf("Введите размер матрицы N: ");
    scanf("%d", &N);

    // Создание и заполнение матрицы
    int matrix[N][N];
    int value = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = value++;
        }
    }

    // Вывод матрицы
    printf("Квадратная матрица %d на %d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
