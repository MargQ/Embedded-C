#include <stdio.h>

int main() {
    int N;

    // Ввод размера массива
    printf("Введите размер массива [N]: ");
    scanf("%d", &N);

    // Ввод элементов массива
    int array[N];
    printf("Введите %d элементов массива:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    // Вывод массива в обратном порядке
    printf("Массив в обратном порядке:\n");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
