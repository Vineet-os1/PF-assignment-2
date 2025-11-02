#include <stdio.h>

#define MAX 100

void push(int stack[], int *top, int max);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[MAX], top = -1, choice;
    
    printf("Stack Implementation\n");
    
    do {
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: push(stack, &top, MAX); break;
            case 2: pop(stack, &top); break;
            case 3: peek(stack, top); break;
            case 4: display(stack, top); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid!\n");
        }
    } while (choice != 5);
    
    return 0;
}

void push(int stack[], int *top, int max) {
    if (*top >= max - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    
    int value;
    printf("Enter value: ");
    scanf("%d", &value);
    
    (*top)++;
    stack[*top] = value;
    printf("Pushed %d\n", value);
}

void pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack Underflow!\n");
        return;
    }
    
    printf("Popped %d\n", stack[*top]);
    (*top)--;
}

void peek(int stack[], int top) {
    if (top < 0) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Top element: %d\n", stack[top]);
}

void display(int stack[], int top) {
    if (top < 0) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
