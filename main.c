#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 30

struct person {
    char fullName[MAX_LENGTH];
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    int wallet;
};

struct bankAccount {
    char accountHolder[MAX_LENGTH];
    int balance;
};

int main() {
    struct person *personPtr;
    personPtr = (struct person*) malloc(1 * sizeof(struct person));

    int c1;
    int c2;

    printf("Hello, user! Input your first name here: ");
    scanf("%15s", (personPtr)->firstName);

    while ((c1 = fgetc(stdin)) != '\n' && c1 != EOF);
    
    printf("Input your last name here: ");
    scanf("%15s", (personPtr)->lastName);
    
    while ((c2 = fgetc(stdin)) != '\n' && c2 != EOF);
    
    strcat((personPtr)->fullName, (personPtr)->firstName);
    strcat((personPtr)->fullName, " ");
    strcat((personPtr)->fullName, (personPtr)->lastName);
    
    printf("\nHello, %s! A bank account will be registered under your name.\n", (personPtr)->fullName);
    
    fflush(stdin);
    while (getchar() != '\n');
    getchar();
    
    printf("Starting registration...\n");
    
    struct bankAccount *accountPtr;
    accountPtr = (struct bankAccount*) malloc(1 * sizeof(struct bankAccount));
    
    strcpy((accountPtr)->accountHolder, (personPtr)->fullName);
    printf("A back account was registered under the name of: %s", (accountPtr)->accountHolder);
    
    return 0;
}