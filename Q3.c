#include <stdio.h>

#define ROWS 5
#define COLS 5

void updateStatus(int grid[ROWS][COLS]);
void queryStatus(int grid[ROWS][COLS]);
void runDiagnostic(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {0};
    int choice;
    
    printf("IESCO Power Grid System\n");
    
    do {
        printf("\n1. Update Sector\n2. Query Sector\n3. Run Diagnostic\n4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: updateStatus(grid); break;
            case 2: queryStatus(grid); break;
            case 3: runDiagnostic(grid); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid!\n");
        }
    } while (choice != 4);
    
    return 0;
}

void updateStatus(int grid[ROWS][COLS]) {
    int row, col, bit, action;
    
    printf("Row (0-4): ");
    scanf("%d", &row);
    printf("Col (0-4): ");
    scanf("%d", &col);
    
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid!\n");
        return;
    }
    
    printf("Flag (0=Power, 1=Overload, 2=Maintenance): ");
    scanf("%d", &bit);
    printf("Action (1=Set, 0=Clear): ");
    scanf("%d", &action);
    
    if (action == 1)
        grid[row][col] |= (1 << bit);
    else
        grid[row][col] &= ~(1 << bit);
    
    printf("Updated!\n");
}

void queryStatus(int grid[ROWS][COLS]) {
    int row, col;
    
    printf("Row (0-4): ");
    scanf("%d", &row);
    printf("Col (0-4): ");
    scanf("%d", &col);
    
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid!\n");
        return;
    }
    
    int status = grid[row][col];
    
    printf("\n--- Sector [%d][%d] ---\n", row, col);
    printf("Power: %s\n", (status & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & 2) ? "YES" : "NO");
    printf("Maintenance: %s\n", (status & 4) ? "YES" : "NO");
}

void runDiagnostic(int grid[ROWS][COLS]) {
    int overload = 0, maintenance = 0;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & 2) overload++;
            if (grid[i][j] & 4) maintenance++;
        }
    }
    
    printf("\n--- DIAGNOSTIC ---\n");
    printf("Overloaded sectors: %d\n", overload);
    printf("Maintenance required: %d\n", maintenance);
}
