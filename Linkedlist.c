#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для представлення книги
typedef struct Book {
    char title[100];
    double price;
    int pages;
    char language[30];
    double weight;
    int year;
    struct Book *next; // Вказівник на наступну книгу у списку
} Book;

// Функція для створення нової книги
Book* createBook(const char *title, double price, int pages, const char *language, double weight, int year) {
    Book *newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}

// Функція для додавання книги до списку
void addBook(Book **head, const char *title, double price, int pages, const char *language, double weight, int year) {
    Book *newBook = createBook(title, price, pages, language, weight, year);
    if (*head == NULL) {
        *head = newBook;
    } else {
        Book *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

// Функція для виведення інформації про всі книги
void printBooks(Book *head) {
    Book *temp = head;
    while (temp != NULL) {
        printf("Title: %s\n", temp->title);
        printf("Price: $%.2f\n", temp->price);
        printf("Pages: %d\n", temp->pages);
        printf("Language: %s\n", temp->language);
        printf("Weight: %.2f kg\n", temp->weight);
        printf("Year of Publication: %d\n", temp->year);
        printf("------------------------\n");
        temp = temp->next;
    }
}

// Функція для звільнення пам'яті, зайнятої списком
void freeBooks(Book *head) {
    Book *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Book *head = NULL; // Ініціалізація голови списку

    // Додавання книг до списку
    addBook(&head, "Harry Potter and the Philosopher's Stone", 19.99, 223, "English", 0.3, 1997);
    addBook(&head, "Harry Potter and the Chamber of Secrets", 22.50, 251, "English", 0.35, 1998);
    addBook(&head, "Harry Potter and the Prisoner of Azkaban", 24.99, 317, "English", 0.4, 1999);
    addBook(&head, "Harry Potter and the Goblet of Fire", 29.99, 636, "English", 0.6, 2000);
    addBook(&head, "Harry Potter and the Order of the Phoenix", 32.99, 766, "English", 0.7, 2003);
    addBook(&head, "Harry Potter and the Half-Blood Prince", 27.99, 607, "English", 0.65, 2005);
    addBook(&head, "Harry Potter and the Deathly Hallows", 34.99, 607, "English", 0.65, 2007);

    // Виведення інформації про всі книги
    printf("Harry Potter Book Series Information:\n");
    printf("------------------------\n");
    printBooks(head);

    // Звільнення пам'яті
    freeBooks(head);

    return 0;
}
