#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Constants 
#define MAX_LENGTH 30

// Variables 
int distributedTime = 0;

// Functions 
void wait(float s) {
    distributedTime += s * 1000;
    while (clock() < ((s * 1000) + (distributedTime - s * 1000)) * 1000);
}

// Structs 
struct person {
    char fullName[MAX_LENGTH];
    char firstName[MAX_LENGTH / 2];
    char lastName[MAX_LENGTH / 2];

    int cash;
};

struct bankAccount {
    char accountHolder[MAX_LENGTH];
    int balance;
};

// Runtime 
int main() {
    struct person *personPtr;
    personPtr = (struct person*) malloc(1 * sizeof(struct person));

    (personPtr) -> cash += 50;

    int c1;
    int c2;

    printf("Hello, user! Input your first name here: ");
    scanf("%15s", (personPtr) -> firstName);

    while ((c1 = fgetc(stdin)) != '\n' && c1 != EOF);
    
    printf("Input your last name here: ");
    scanf("%15s", (personPtr) -> lastName);
    
    while ((c2 = fgetc(stdin)) != '\n' && c2 != EOF);
    
    strcat((personPtr) -> fullName, (personPtr) -> firstName);
    strcat((personPtr) -> fullName, " ");
    strcat((personPtr) -> fullName, (personPtr) -> lastName);
    
    printf("\nHello, %s! A bank account will be registered under your name.\n", (personPtr) -> fullName);

    wait(1.5);
    printf("Starting registration...\n");
    wait(2);

    struct bankAccount *accountPtr;
    accountPtr = (struct bankAccount*) malloc(1 * sizeof(struct bankAccount));
    
    strcpy((accountPtr) -> accountHolder, (personPtr) -> fullName);
    printf("A back account was registered under the name of: %s\n\n", (accountPtr) -> accountHolder);
    
    wait(1.5);
    printf("Would you like to withdraw or deposit?");
    wait(0.35);
    printf("\n1: Deposit\n2: Withdraw\n\nI choose: ");
    
    int option, amt;
    scanf("%d", &option);

    if (option == 1) {
        printf("How much would you like to deposit? (no commas)");
        wait(0.35);
        printf("\n\nI would like to deposit: ");

        scanf("%d", &amt);

        if ((personPtr) -> cash < amt) {
            printf("You do not have enough cash in your wallet to deposit $%d.\n", amt);
            return 0;
        } else if (amt < 0) {
            printf("Invalid deposit amount.\n");
            return 0;
        }

        (accountPtr) -> balance += amt;
        (personPtr) -> cash -= amt;

        printf("Successfully deposited $%d into your account!\n\nYour new bank balance: $%d\nAmount of cash in your wallet: $%d\n", amt, (accountPtr)->balance, (personPtr)->cash);
    
    } else if (option == 2) {
        printf("How much would you like to withdraw? (no commas)\n\nI would like to withdraw: ");
        scanf("%d", &amt);

        if ((accountPtr) -> balance < amt) {
            printf("You do not have enough cash in your bank to withdraw $%d.\n", amt);
            return 0;
        } else if (amt < 0) {
            printf("Invalid withdrawal amount.\n");
            return 0;
        }

        (accountPtr) -> balance -= amt;
        (personPtr) -> cash += amt;

        printf("Successfully withdrawed $%d from your account!\n\nAmount of cash in your wallet: $%d\nYour new bank balance: $%d\n", amt, (personPtr)->cash, (accountPtr)->balance);
    
    } else {
        printf("That's not a valid option!\n");
    }

    return 0;
}