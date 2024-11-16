#include <stdio.h>

int main() {
    int N;

    // Ввод размера матрицы
    printf("Введите размер квадратной матрицы N: ");
    scanf("%d", &N);

    // Создание и заполнение матрицы
    int matrix[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= i) {  // Верхний треугольник
                matrix[i][j] = 1;
            } else {  // Нижний треугольник
                matrix[i][j] = 0;
            }
        }
    }

    // Вывод матрицы
    printf("Результат:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
