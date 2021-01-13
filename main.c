#include <stdio.h>
#include <stdlib.h>

#include "BankDatabase.h"
#include "errorMessage.h"

#define BANK_NAME "Itau"

int showMenu();
void menu();
void registerSubrotine();
void listAccounts();
void removeSubrotine();
void depositSubrotine();
void withdrawSubrotine();
void transferSubrotine();

int main(){
    do{
        menu(showMenu());
        system("cls");
    }while(1);
}

int showMenu(){
    printf("Welcome to %s\n", BANK_NAME);
    printf("|1| - Register an account\n");
    printf("|2| - List accounts\n");
    printf("|3| - Remove an account\n");
    printf("|4| - Deposit\n");
    printf("|5| - Withdraw\n");
    printf("|6| - Transfer\n");
    printf("|7| - Exit\n");

    int number;
    scanf("%i", &number);
    return number;
}

void menu(int option){
    switch(option){
    case 1:
        registerSubrotine();
        system("pause");
        break;
    case 2:
        listAccounts();
        system("pause");
        break;
    case 3:
        removeSubrotine();
        system("pause");
        break;
    case 4:
        depositSubrotine();
        break;
    case 5:
        withdrawSubrotine();
        break;
    case 6:
        transferSubrotine();
        break;
    case 7:
        system("exit");
        break;
    default:
        notValidEntry();
        break;
    }
}

void registerSubrotine(){
    char name[100];
    int age;
    char gender;

    printf("Enter the name!\n");
    scanf("%s", &name);
    fflush(stdin);
    printf("Enter the age!\n");
    scanf("%i", &age);
    fflush(stdin);
    printf("Enter the gender!\n");
    scanf("%c", &gender);
    fflush(stdin);

    createAccount(name, age, gender);
}

void listAccounts(){
    printf(showAccounts());
}

void removeSubrotine(){
    printf("Enter the account id!\n");
    int id;
    scanf("%i", &id);

    removeAccount(id);
}

void depositSubrotine(){
    printf("Enter the account ID!\n");
    int id;
    scanf("%i", &id);

    printf("Enter the money quantity!\n");
    float money;
    scanf("%f", &money);

    verifyError(executeDeposit(id, money));
}

void withdrawSubrotine(){
    printf("Enter the account ID!\n");
    int id;
    scanf("%i", &id);

    printf("Enter the money quantity!\n");
    float money;
    scanf("%f", &money);

    verifyError(executeWithdraw(id, money));
}

void transferSubrotine(){
    printf("Enter the account ID!\n");
    int id;
    scanf("%i", &id);

    printf("Enter the money quantity!\n");
    float money;
    scanf("%f", &money);

    printf("Enter the destiny account ID!\n");
    int destinyId;
    scanf("%i", &destinyId);

    verifyError(executeTransfer(id, money, destinyId));
}
