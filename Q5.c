#include <stdio.h>
#include <string.h>

void encodeMessage(char msg[]);
void decodeMessage(char msg[]);

int main() {
    char msg[500];
    int choice;
    
    printf("TCS Message Encoder/Decoder\n");
    
    do {
        printf("\n1. Encode\n2. Decode\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                printf("Enter message: ");
                fgets(msg, 500, stdin);
                msg[strcspn(msg, "\n")] = '\0';
                encodeMessage(msg);
                printf("Encoded: %s\n", msg);
                break;
            case 2:
                printf("Enter encoded message: ");
                fgets(msg, 500, stdin);
                msg[strcspn(msg, "\n")] = '\0';
                decodeMessage(msg);
                printf("Decoded: %s\n", msg);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid!\n");
        }
    } while (choice != 3);
    
    return 0;
}

void encodeMessage(char msg[]) {
    int len = strlen(msg);
    
    // Step 1: Reverse the string
    for (int i = 0; i < len / 2; i++) {
        char temp = msg[i];
        msg[i] = msg[len - 1 - i];
        msg[len - 1 - i] = temp;
    }
    
    // Step 2: Toggle 2nd and 5th bits
    for (int i = 0; i < len; i++) {
        msg[i] ^= 0x12;  // Toggle bit 1 (2nd bit) and bit 4 (5th bit)
    }
}

void decodeMessage(char msg[]) {
    int len = strlen(msg);
    
    // Step 1: Toggle 2nd and 5th bits (untoggle)
    for (int i = 0; i < len; i++) {
        msg[i] ^= 0x12;  // Same operation reverses the toggle
    }
    
    // Step 2: Reverse the string
    for (int i = 0; i < len / 2; i++) {
        char temp = msg[i];
        msg[i] = msg[len - 1 - i];
        msg[len - 1 - i] = temp;
    }
}
