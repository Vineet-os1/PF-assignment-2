#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount);
void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount);
void generateLowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount);

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int bookCount = 0;
    int choice;
    printf("Liberty Books Inventory System\n\n");
    do {
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addNewBook(isbns, titles, prices, quantities, &bookCount);
                break;
            case 2:
                processSale(isbns, titles, prices, quantities, bookCount);
                break;
            case 3:
                generateLowStockReport(isbns, titles, prices, quantities, bookCount);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
        
    } while (choice != 4);
    
    return 0;
}

void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Inventory full!\n");
        return;
    }
    
    int isbn;
    printf("Enter ISBN: ");
    scanf("%d", &isbn);
    printf("Enter Title: ");
    getchar(); // Clear newline
    fgets(titles[*bookCount], 50, stdin);
    titles[*bookCount][strcspn(titles[*bookCount], "\n")] = '\0';
    
    printf("Enter Price: ");
    scanf("%f", &prices[*bookCount]);
    
    printf("Enter Quantity: ");
    scanf("%d", &quantities[*bookCount]);
    
    isbns[*bookCount] = isbn;
    (*bookCount)++;
    
    printf("Book added successfully!\n");
}

void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount) {
    int isbn, copiesSold, found = -1;
    
    printf("Enter ISBN: ");
    scanf("%d", &isbn);
    
    // Find book by ISBN
    for (int i = 0; i < bookCount; i++) {
        if (isbns[i] == isbn) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Book not found!\n");
        return;
    }
    
    printf("Enter copies to sell: ");
    scanf("%d", &copiesSold);
    
    if (copiesSold > quantities[found]) {
        printf("Out of stock! Only %d available.\n", quantities[found]);
        return;
    }
    
    quantities[found] -= copiesSold;
    printf("Sale processed! Remaining: %d\n", quantities[found]);
}

void generateLowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount) {
    printf("Low-Stock Report (Quantity < 5):\n");
    printf("----------------------------------\n");
    
    int count = 0;
    for (int i = 0; i < bookCount; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d\n", isbns[i]);
            printf("Title: %s\n", titles[i]);
            printf("Price: %.2f\n", prices[i]);
            printf("Quantity: %d\n", quantities[i]);
            printf("----------------------------------\n");
            count++;
        }
    }
    
    if (count == 0) {
        printf("No low-stock books.\n");
    }
}
