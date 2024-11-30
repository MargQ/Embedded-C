#include <stdio.h>
#include <string.h>

#define MAX_ABONENTS 100

struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};

// Функции для меню
void add_abonent(struct abonent phonebook[], int *i);
void delete_abonent(struct abonent phonebook[], int *i);
void search_abonent(struct abonent phonebook[], int i);
void print_all_abonents(struct abonent phonebook[], int i);

int main() {
    struct abonent phonebook[MAX_ABONENTS] = {0}; // Массив абонентов
    int i = 0; // Количество добавленных абонентов
    int choice;

    while (1) {
        // Меню программы
        printf("\nАбонентский справочник:\n");
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонентов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        printf("Введите пункт меню: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_abonent(phonebook, &i);
                break;
            case 2:
                delete_abonent(phonebook, &i);
                break;
            case 3:
                search_abonent(phonebook, i);
                break;
            case 4:
                print_all_abonents(phonebook, i);
                break;
            case 5:
                printf("Выход из программы.\n");
                return 0;
            default:
                printf("Неверный пункт меню. Попробуйте снова.\n");
        }
    }
}

// Добавление абонента
void add_abonent(struct abonent phonebook[], int *i) {
    if (*i >= MAX_ABONENTS) {
        printf("Справочник переполнен. Невозможно добавить нового абонента.\n");
        return;
    }

    printf("Введите имя: ");
    scanf("%9s", phonebook[*i].name);
    printf("Введите фамилию: ");
    scanf("%9s", phonebook[*i].second_name);
    printf("Введите телефон: ");
    scanf("%9s", phonebook[*i].tel);

    (*i)++;
    printf("Абонент добавлен.\n");
}

// Удаление абонента
void delete_abonent(struct abonent phonebook[], int *i) {
    if (*i == 0) {
        printf("Справочник пуст.\n");
        return;
    }

    char tel[10];
    printf("Введите телефон абонента для удаления: ");
    scanf("%9s", tel);

    for (int j = 0; j < *i; j++) {
        if (strcmp(phonebook[j].tel, tel) == 0) {
            // Очистка структуры
            memset(&phonebook[j], 0, sizeof(struct abonent));
            // Сдвиг элементов
            for (int k = j; k < *i - 1; k++) {
                phonebook[k] = phonebook[k + 1];
            }
            (*i)--;
            printf("Абонент удален.\n");
            return;
        }
    }
    printf("Абонент с таким телефоном не найден.\n");
}

// Поиск абонентов по имени
void search_abonent(struct abonent phonebook[], int i) {
    char name[10];
    printf("Введите имя для поиска: ");
    scanf("%9s", name);

    int found = 0;
    for (int j = 0; j < i; j++) {
        if (strcmp(phonebook[j].name, name) == 0) {
            printf("Абонент: %s %s, Телефон: %s\n", phonebook[j].name, phonebook[j].second_name, phonebook[j].tel);
            found = 1;
        }
    }

    if (!found) {
        printf("Абоненты с именем '%s' не найдены.\n");
    }
}

// Вывод всех абонентов
void print_all_abonents(struct abonent phonebook[], int i) {
    if (i == 0) {
        printf("Справочник пуст.\n");
        return;
    }

    for (int j = 0; j < i; j++) {
        printf("%d. %s %s, Телефон: %s\n", j + 1, phonebook[j].name, phonebook[j].second_name, phonebook[j].tel);
    }
}
