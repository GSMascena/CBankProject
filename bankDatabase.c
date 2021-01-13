#include "bankDatabase.h"
#include "accountList.h"
#include "account.h"
#include "client.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Procedure that creates an account and adds to the database, if it's not full
int createAccount(char* name, int age, char gender){
    Account account;
    Client client;

    strcpy(client.name, name);
    client.age = age;
    client.gender = gender;
    account.id = (locateFreeIndex() + 1);

    account.client = client;

    if(account.id != 0){
        account.isValid = 1;

        accountList[account.id - 1] = account;

        return 0;
    }

    return -1;
}

//Procedure that search a client by an id and delete it from the database using
void removeAccount(int id){

    int index = id - 1;
    while(accountList[index].isValid == 1 || index != (accountListSize - 1)){
        accountList[index] = accountList[index + 1];
        accountList[index].id -= 1;
        index++;
    }

    if(index == (accountListSize - 1)){
        accountList[index].isValid = 0;
    }
}

//Procedure that execute a deposit
int executeDeposit(int id, float money){
    if((id-1) >= 0 && (id-1) <= 99){
        if(accountList[id-1].isValid == 1){
            accountList[id-1].deposit += money;
            return 1;
        }
        return -1;
    }
    return 0;
}

//Procedure that execute a withdraw
int executeWithdraw(int id, float money){

    if((id-1) >= 0 && (id-1) <= 99){
        if(accountList[id-1].isValid == 1){
            if((accountList[id-1].deposit - money) >= 0){
                accountList[id-1].deposit -= money;
                return 1;
            }
            return -2;
        }
        return -1;
    }
    return 0;
}

//Procedure that execute a transfer
int executeTransfer(int id, float money, int destinyId){
    if((id-1) >= 0 && (id-1) <= 99){
        if(accountList[id-1].isValid == 1){
            if((accountList[id-1].deposit - money) >= 0){
                if((destinyId-1) >= 0 && (destinyId-1) <= 99){
                    if(accountList[destinyId-1].isValid == 1){
                        accountList[id-1].deposit -= money;
                        accountList[destinyId-1].deposit += money;
                        return 1;
                    }
                    return -4;
                }
                return -3;
            }
            return -2;
        }
        return -1;
    }
    return 0;
}

//Function that search for a not valid entry in the database that can be overwritten
int locateFreeIndex(){
    int index = 0;
    while(accountList[index].isValid == 1 && index <= (accountListSize - 1) ){
        index++;
    }

    if(index > (accountListSize - 1)){
        return -1;
    }

    return index;
}

//Function that returns a char array with all accounts
char* showAccounts(){
    int charCount = 0;

    int index = 0;
    while(accountList[index].isValid == 1){

        char buffer[1000];
        charCount += sizeof("___________________\n");
        charCount += (sizeof("Account Number: ") + sizeof(accountList[index].id) + sizeof("\n"));
        charCount += (sizeof("Name: ") + sizeof(accountList[index].client.name) + sizeof("\n"));
        charCount += (sizeof("Age: ") + sizeof(accountList[index].client.age) + sizeof("\n"));
        charCount += (sizeof("Deposit: ") + sizeof(accountList[index].deposit) + sizeof("\n"));
        /*charCount += sprintf(buffer, "Account Number: %i\n", accountList[index].id);
        charCount += sprintf(buffer, "Name: %s\n", accountList[index].client.name);
        charCount += sprintf(buffer, "Age: %i\n", accountList[index].client.age);
        charCount += sprintf(buffer, "Deposit: %.2f\n", accountList[index].deposit);*/

        index++;
    }

    char* dialogue = malloc(charCount);

    strcpy(dialogue, "");

    index = 0;
    while(accountList[index].isValid == 1){
        char buffer[100];
        strcat(dialogue, "___________________\n");
        sprintf(buffer, "Account Number: %i\n", accountList[index].id);
        strcat(dialogue, buffer);
        sprintf(buffer, "Name: %s\n", accountList[index].client.name);
        strcat(dialogue, buffer);
        sprintf(buffer, "Age: %i\n", accountList[index].client.age);
        strcat(dialogue, buffer);
        sprintf(buffer, "Deposit: %.2f\n", accountList[index].deposit);
        strcat(dialogue, buffer);

        index++;
    }

    return dialogue;
}

//Auxiliary function to count characters
int charCounter(char* text){
    int count = 0;

    while(text[count] != '\0'){
        count++;
    }

    return count;
}
