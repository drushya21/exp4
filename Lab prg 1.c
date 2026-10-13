
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
int book_id;
char title[100];
char author[100];
float price;
int is_available;
} Book;
book* create(int *n);
void display(Book *books, int n);
void search(Book *books, int n, int id);
void issueBook(Book *books, int n, int id);
void returbBook(Book *books, int n, int id);
int main(){
    Book *library = NULL;
    int n = 0;
    int choice, id;

    while (1){
        printf("\n--- Library Management System ---\n");
        printf("1. Add/Create Book Records\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
         case 1:

              if (library != NULL){
              free(library);
              }
              library = create(&n);
              break;
         case 2:
              display(library, n);
              break;
         case 3:
              if(library == NULL || n == 0){
                 printf("Library is empty. Pleas add books first.\n");
              } else {
                  printf("Enter Book ID to search: ");
                  scanf("%d", &id);
                  search(library, n, id);
              }
              break;
         case 4:
               if(library == NULL || n == 0){
                 printf("Library is empty. Pleas add books first.\n");
              } else {
                  printf("Enter Book ID to issue: ");
                  scanf("%d", &id);
                  issueBook(library, n, id);
              }
              break;
          case 5:
               if (library == Null || n == 0) {
                   printf("Library is empty. Please add books first.\n");
               } else {
                     printf("Enter Book ID to return: ");
                  scanf("%d", &id);
                  returnBook(library, n, id);
              }
              break;
          case 6:
               if (library != Null {
                   free(library);
               }
               printf("Exiting program. Goodbye!\n");
               exit(0);
          default:
              printf("Invalid choice! Please try again\n");
        }
    }
    return 0;
}

Book* create(int *n) {
    printf("Enter the number of books (N): ");
    scanf("%d", n);

    if (*n <= 0) {
        printf("Invalid number of  books!\n");
        return NULL;
    }
    Book *books = (Book*) malloc((*n) * sizeof(Book));
    if (books == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i< *n; i++) {
        printf("\nEnter details for Book %d:\n", i+1);
        printf("BoOK ID: ");
        scanf("%d",&books[i].book_id);

        getchar();
        printf("Title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0;

        printf("Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;

        printf("Price: ");
        scanf("%f" , &books[i].price);

        books[i].is_available = 1;
    }

    printf("\nSuccessfully created records for %d books!\n", *n);
    return books;
}

void display(Book *books, int n) {
    if (books == NULL || n == o){
        printf("No records available to display.\n");
        return;

    }
printf("\n---------------------------------------------------------------\n";)
    printf("%-10s %-25 %-20 %10s %15s\n", "Book ID", "Title", "Author", "Price", "Status");


