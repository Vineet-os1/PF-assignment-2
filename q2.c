#include <stdio.h>
#include <string.h>

// Global variables
char name[50], cnic[20];
int stock[4] = {50, 10, 20, 8};
float prices[4] = {100, 200, 300, 150};
int cart[4] = {0, 0, 0, 0};

// Functions
void customerInfo();
void displayInventory();
void updateInventory();
void addToCart();
void displayBill();
void showInvoice();

int main() {
    int choice;
    
    printf("SUPERMARKET SYSTEM\n");
    
    do {
        printf("\n1. Customer Info\n2. Display Inventory\n3. Update Inventory\n");
        printf("4. Add to Cart\n5. Display Bill\n6. Show Invoice\n7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: customerInfo(); break;
            case 2: displayInventory(); break;
            case 3: updateInventory(); break;
            case 4: addToCart(); break;
            case 5: displayBill(); break;
            case 6: showInvoice(); break;
            case 7: printf("Goodbye!\n"); break;
            default: printf("Invalid!\n");
        }
    } while (choice != 7);
    
    return 0;
}

void customerInfo() {
    printf("Enter name: ");
    getchar();
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter CNIC: ");
    fgets(cnic, 20, stdin);
    cnic[strcspn(cnic, "\n")] = '\0';
    printf("Saved!\n");
}

void displayInventory() {
    printf("\nCode\tStock\tPrice\n");
    for (int i = 0; i < 4; i++) {
        printf("00%d\t%d\t%.2f\n", i+1, stock[i], prices[i]);
    }
}

void updateInventory() {
    int code, qty;
    printf("Product code (1-4): ");
    scanf("%d", &code);
    if (code < 1 || code > 4) {
        printf("Invalid!\n");
        return;
    }
    printf("New quantity: ");
    scanf("%d", &qty);
    stock[code-1] = qty;
    printf("Updated!\n");
}

void addToCart() {
    int code, qty;
    displayInventory();
    printf("\nProduct code (1-4): ");
    scanf("%d", &code);
    if (code < 1 || code > 4) {
        printf("Invalid!\n");
        return;
    }
    printf("Quantity: ");
    scanf("%d", &qty);
    
    if (qty > stock[code-1]) {
        printf("Only %d available!\n", stock[code-1]);
        return;
    }
    
    cart[code-1] += qty;
    stock[code-1] -= qty;
    printf("Added!\n");
}

void displayBill() {
    float total = 0;
    printf("\nCode\tQty\tPrice\tSubtotal\n");
    for (int i = 0; i < 4; i++) {
        if (cart[i] > 0) {
            float sub = cart[i] * prices[i];
            printf("00%d\t%d\t%.2f\t%.2f\n", i+1, cart[i], prices[i], sub);
            total += sub;
        }
    }
    printf("Total: %.2f\n", total);
    
    char promo[20];
    printf("Have promocode? (yes/no): ");
    scanf("%s", promo);
    if (strcmp(promo, "yes") == 0) {
        printf("Enter code: ");
        scanf("%s", promo);
        if (strcmp(promo, "Eid2025") == 0) {
            float discount = total * 0.25;
            printf("Discount (25%%): %.2f\n", discount);
            printf("Final Total: %.2f\n", total - discount);
        } else {
            printf("Invalid code!\n");
        }
    }
}

void showInvoice() {
    float total = 0;
    printf("\n======= INVOICE =======\n");
    printf("Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("=======================\n");
    printf("Code\tQty\tSubtotal\n");
    for (int i = 0; i < 4; i++) {
        if (cart[i] > 0) {
            float sub = cart[i] * prices[i];
            printf("00%d\t%d\t%.2f\n", i+1, cart[i], sub);
            total += sub;
        }
    }
    printf("=======================\n");
    printf("Total: %.2f\n", total);
    
    char promo[20];
    printf("Have promocode? (yes/no): ");
    scanf("%s", promo);
    if (strcmp(promo, "yes") == 0) {
        printf("Enter code: ");
        scanf("%s", promo);
        if (strcmp(promo, "Eid2025") == 0) {
            float discount = total * 0.25;
            printf("Discount: %.2f\n", discount);
            printf("Final: %.2f\n", total - discount);
        }
    }
    printf("=======================\n");
}
