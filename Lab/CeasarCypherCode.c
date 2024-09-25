#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

char string1[MAX_LENGTH];
char string2[MAX_LENGTH];
int key;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void encode() {
    printf("Please enter the original message: \n");
    fgets(string1, MAX_LENGTH, stdin);
    string1[strcspn(string1, "\n")] = 0;  // Remove trailing newline

    printf("Please enter the key: \n");
    while (scanf("%d", &key) != 1) {
        printf("Invalid input. Please enter a number for the key: \n");
        clearInputBuffer();
    }
    clearInputBuffer();

    for (int i = 0; i < strlen(string1); i++) {
        if (isalpha(string1[i])) {
            char base = isupper(string1[i]) ? 'A' : 'a';
            string2[i] = ((string1[i] - base + key) % 26) + base;
        } else {
            string2[i] = string1[i];
        }
    }
    string2[strlen(string1)] = '\0';
    printf("The encoded message is: %s\n", string2);
}

void decode() {
    printf("Please enter the encoded message: \n");
    fgets(string1, MAX_LENGTH, stdin);
    string1[strcspn(string1, "\n")] = 0;  // Remove trailing newline

    printf("Please enter the key: \n");
    while (scanf("%d", &key) != 1) {
        printf("Invalid input. Please enter a number for the key: \n");
        clearInputBuffer();
    }
    clearInputBuffer();

    for (int i = 0; i < strlen(string1); i++) {
        if (isalpha(string1[i])) {
            char base = isupper(string1[i]) ? 'A' : 'a';
            string2[i] = ((string1[i] - base - key + 26) % 26) + base;
        } else {
            string2[i] = string1[i];
        }
    }
    string2[strlen(string1)] = '\0';
    printf("The decoded message is: %s\n", string2);
}

int main() {
    char decision[10];
    printf("Would you like to encode or decode a message? (encode/decode): ");
    scanf("%s", decision);
    clearInputBuffer();

    if (strcmp(decision, "encode") == 0) {
        encode();
    } else if (strcmp(decision, "decode") == 0) {
        decode();
    } else {
        printf("Invalid option. Please choose 'encode' or 'decode'.\n");
    }
    return 0;
}
