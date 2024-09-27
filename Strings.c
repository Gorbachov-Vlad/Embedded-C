#include <stdio.h>
#include <string.h> // Додаємо цей заголовковий файл

// Функція для злиття двох строк по символах
void mergeStrings(char *str1, char *str2, char *result) {
    int i = 0, j = 0, k = 0;

    // Об'єднуємо строки, по черзі додаючи символи з кожної строки
    while (str1[i] != '\0' && str2[j] != '\0') {
        result[k++] = str1[i++];
        result[k++] = str2[j++];
    }

    // Додаємо залишок з першої строки, якщо друга закінчилась
    while (str1[i] != '\0') {
        result[k++] = str1[i++];
    }

    // Додаємо залишок з другої строки, якщо перша закінчилась
    while (str2[j] != '\0') {
        result[k++] = str2[j++];
    }

    result[k] = '\0'; // Завершення результатної строки нульовим символом
}

int main() {
    char str1[100], str2[100], result[200];

    // Введення першої строки
    printf("Input the first string: ");
    fgets(str1, sizeof(str1), stdin);

    // Введення другої строки
    printf("Input the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Видалення символу нового рядка, якщо він є
    if (str1[strlen(str1) - 1] == '\n') str1[strlen(str1) - 1] = '\0';
    if (str2[strlen(str2) - 1] == '\n') str2[strlen(str2) - 1] = '\0';

    // Виклик функції злиття строк
    mergeStrings(str1, str2, result);

    // Виведення результату
    printf("Merging strings: %s\n", result);

    return 0;
}
