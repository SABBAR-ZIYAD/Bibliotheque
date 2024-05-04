#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char firstname[10];
    char lastname[10];
} user;

typedef struct {
    int id;
    char title[20];
    char author[20];
    char description[200];
    user userr; 
    float price;
    char category[20];
    char availability[4]; 
} Book;

Book *library;
int i, p, pos;
char title[20];
char author[20];

void displayBook(const Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Description: %s\n", book->description);
    printf("User: %s %s\n", book->userr.firstname, book->userr.lastname);
    printf("Price: %.2fdh\n", book->price);
    printf("Category: %s\n", book->category);
    printf("Availability: %s\n", book->availability);
    printf("\n");
}

void displayBookToFile(const Book *book, FILE *file) {
    fprintf(file, "Title: %s\n", book->title);
    fprintf(file, "Author: %s\n", book->author);
    fprintf(file, "Description: %s\n", book->description);
    fprintf(file, "User: %s %s\n", book->userr.firstname, book->userr.lastname);
    fprintf(file, "Price: %.2fdh\n", book->price);
    fprintf(file, "Category: %s\n", book->category);
    fprintf(file, "Availability: %s\n", book->availability);
    fprintf(file, "\n");
}

void InsertData(Book *library, int n, user *tmp) {
    for (i = 0; i < n; i++) {
        printf("\nEnter details of book %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &(library + i)->id);
        printf("Title: ");
        scanf("%s", (library + i)->title);
        printf("Author: ");
        scanf("%s", (library + i)->author);
        printf("Description: ");
        scanf(" %[^\n]", (library + i)->description);
        //username
        strcpy((library + i)->userr.firstname, tmp->firstname);
        strcpy((library + i)->userr.lastname, tmp->lastname);
        printf("Price: ");
        scanf("%f", &(library + i)->price);
        printf("Category: ");
        scanf("%s", (library + i)->category);
        printf("Availability (yes/no): ");
        scanf("%s", (library + i)->availability);
    }
}

void AddBook(Book **library, int *numBooks) {
    *library = (Book *)realloc(*library, (*numBooks + 1) * sizeof(Book));
    if (*library == NULL) {
        printf("Memory reallocation failed\n");
        return;
    }

    printf("\nEnter details of book %d:\n", *numBooks + 1);
    printf("ID: ");
    scanf("%d", &((*library + *numBooks)->id));
    printf("Title: ");
    scanf("%s", ((*library + *numBooks)->title));
    printf("Author: ");
    scanf("%s", ((*library + *numBooks)->author));
    printf("Description: ");
    scanf(" %[^\n]", ((*library + *numBooks)->description));
    printf("User's first name: ");
    scanf("%s", ((*library + *numBooks)->userr.firstname));
    printf("User's last name: ");
    scanf("%s", ((*library + *numBooks)->userr.lastname)); 
    printf("Price: ");
    scanf("%f", &((*library + *numBooks)->price));
    printf("Category: ");
    scanf("%s", ((*library + *numBooks)->category));
    printf("Availability (yes/no): ");
    scanf("%s", ((*library + *numBooks)->availability));

    (*numBooks)++;
}

void DeleteBook(Book **library, int *numBooks, int p) {
    int i;
    if (p >= *numBooks || p < 1) {
        printf("Invalid book index\n");
        return;
    }

    for (i = p - 1; i < *numBooks - 1; i++) {
        strcpy(((*library + i)->title), ((*library + i + 1)->title));
        ((*library + i)->id) = ((*library + i + 1)->id);
        strcpy(((*library + i)->author), ((*library + i + 1)->author));
        strcpy(((*library + i)->description), ((*library + i + 1)->description));
        ((*library + i)->userr) = ((*library + i + 1)->userr);
        ((*library + i)->price) = ((*library + i + 1)->price);
        strcpy(((*library + i)->category), ((*library + i + 1)->category));
        strcpy(((*library + i)->availability), ((*library + i + 1)->availability));
    }

    *library = (Book *)realloc(*library, (*numBooks - 1) * sizeof(Book));
    if (*library == NULL) {
        printf("Memory reallocation failed\n");
        return;
    }

    (*numBooks)--;
}

void SearchByTitle(Book *library, int n ,char title[20]){
    for(i=0 ; i<n ; i++){
        if(strcmp((library+i)->title,title)==0){
            displayBook(library + i);
        }
    }
}

void SearchByAuthor(Book *library, int n ,char author[20]){
    for(i=0 ; i<n ; i++){
        if(strcmp((library+i)->author,author)==0){
            displayBook(library + i);
        }
    }
}

void sortBooksByTitle(Book *library, int numBooks) {
    Book temp;
    int i, j;
    
    for (i = 0; i < numBooks - 1; i++) {
        for (j = i + 1; j < numBooks; j++) {
            if (strcmp(library[i].title, library[j].title) > 0) {
                // Swap
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }
}

void sortBooksByCategory(Book *library, int numBooks) {
    Book temp;
    int i, j;
    
    for (i = 0; i < numBooks - 1; i++) {
        for (j = i + 1; j < numBooks; j++) {
            if (strcmp(library[i].category, library[j].category) > 0) {
                // Swap
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }
}

int main() {
    user usertmp, *us;
    us = &usertmp;
    printf("Enter your identity:\n");
    printf("First Name: "); 
    scanf("%s", us->firstname);
    printf("Last Name: ");
    scanf("%s", us->lastname);

    int numBooks;
    printf("How many books do you want to input?\n");
    scanf("%d", &numBooks);
    
    library = (Book *)malloc(numBooks * sizeof(Book));
    if (library == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    InsertData(library, numBooks, us);
    int choice;
    printf("\n\n");
    printf("\t\t****LIBRARY MENU**** \n");
    printf("1. Display all books\n");
    printf("2. Display a book\n");
    printf("3. Add a book\n");
    printf("4. Delete a book\n");
    printf("5. Search book\n");
    printf("  a-By ID\n");
    printf("  b-By name\n");
    printf("\n\n");

    FILE *outputFile = fopen("library_output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open file for writing.\n");
        return 1;
    }

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for ( i = 0; i < numBooks; i++) {
                    displayBook(library + i);
                    displayBookToFile(library + i, outputFile);
                }
                break;
            case 2:
            	printf("Enter the position of the book to display: ");
                scanf("%d", &pos);
                Display1Book(library, numBooks, pos);
                break;
            case 3:
                AddBook(&library, &numBooks);
                for ( i = 0; i < numBooks; i++) {
                    displayBook(library + i);
                }
                break;
            case 4:
                printf("Enter the position of the book to delete: ");
                scanf("%d", &p);
                DeleteBook(&library, &numBooks, p);
                for ( i = 0; i < numBooks; i++) {
                    displayBook(library + i);
                }
                break;
            case 5:
                printf("Search\n");
    			printf("Search by title t and a is for author\n");
    			char ch;
    			scanf(" %c", &ch); 
    			switch(ch){
        			case 't': 
            			printf("enter the title:");
            			scanf("%s", title);
            			SearchByTitle(library, numBooks, title); 
            		break;
        			case 'a': 
            			printf("enter the author:");
            			scanf("%s", author);
            			SearchByAuthor(library, numBooks, author); 
            		break; 
        			default:
            			printf("Invalid option\n");
    				}
    				break;
            case 6:
                printf("Sort\n");
    			printf("Sort by title t and c is for category\n");
    			char sortChoice;
    			scanf(" %c", &sortChoice); 
    			switch(sortChoice){
        			case 't': 
            			sortBooksByTitle(library, numBooks);
            			printf("Books sorted by title:\n");
            			for ( i = 0; i < numBooks; i++) {
                		displayBook(library + i);
            			}
            		break;
        			case 'c': 
            			sortBooksByCategory(library, numBooks);
            			printf("Books sorted by category:\n");
            			for ( i = 0; i < numBooks; i++) {
                			displayBook(library + i);
            			}
            		break;
        			default:
            			printf("Invalid option\n");
    				}
    		        break;
            case 0:
                printf("END OF THE PROGRAM");
                fclose(outputFile); 
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    fclose(outputFile); 
    return 0;
}

            

