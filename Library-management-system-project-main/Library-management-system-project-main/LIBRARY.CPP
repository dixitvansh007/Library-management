#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
    int available;
} Book;

Book books[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    if (numBooks == MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter the title of the book: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter the author of the book: ");
    scanf(" %[^\n]", newBook.author);
    newBook.available = 1;

    books[numBooks++] = newBook;
    printf("Book added successfully.\n");
}

void deleteBook() {
    char searchTitle[100];
    printf("Enter the title of the book to delete: ");
    scanf(" %[^\n]", searchTitle);

    int i, found = 0;
    for (i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < numBooks - 1; i++) {
            books[i] = books[i + 1];
        }
        numBooks--;
        printf("Book deleted successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}

void editBook() {
    char searchTitle[100];
    printf("Enter the title of the book to edit: ");
    scanf(" %[^\n]", searchTitle);

    int i, found = 0;
    for (i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Enter the new title of the book: ");
        scanf(" %[^\n]", books[i].title);
        printf("Enter the new author of the book: ");
        scanf(" %[^\n]", books[i].author);
        printf("Book edited successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}

void searchBook() {
    char searchTitle[100];
    printf("Enter the title of the book to search: ");
    scanf(" %[^\n]", searchTitle);

    int i, found = 0;
    for (i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Book found:\n");
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Availability: %s\n", books[i].available ? "Available" : "Not available");
    } else {
        printf("Book not found.\n");
    }
}

void issueBook() {
    char searchTitle[100];
    printf("Enter the title of the book to issue: ");
    scanf(" %[^\n]", searchTitle);

    int i, found = 0;
    for (i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        if (books[i].available) {
            books[i].available = 0;
            printf("Book issued successfully.\n");
        } else {
            printf("Book is already issued.\n");
        }
    } else {
        printf("Book not found.\n");
    }
}

void viewBooks() {
    if (numBooks == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("Library books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Availability: %s\n", books[i].available ? "Available" : "Not available");
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Edit Book\n");
        printf("4. Search Book\n");
        printf("5. Issue Book\n");
        printf("6. View Books\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
                searchBook();
                break;
            case 5:
                issueBook();
                break;
            case 6:
                viewBooks();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
