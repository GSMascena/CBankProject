#include "bankDatabase.h"
#include "accountList.h"
#include "account.h"
#include "client.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Procedure that adds a client to the database, if it's not full
int addClient(char* name, int age, char gender){
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
void removeClient(int id){

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

//Procedure that show all clients in an list form
void showClients(){
    int index = 0;
    while(accountList[index].isValid == 1){
        printf("___________________\n");
        printf("Account Number: %i\n", accountList[index].id);
        printf("Name: %s\n", accountList[index].client.name);
        printf("Age: %i\n", accountList[index].client.age);
        printf("Deposit: %.2f\n", accountList[index].deposit);

        index++;
    }
}

