#include <stdio.h>
#include <stdlib.h>

#include "BankDatabase.h"

#define BANK_NAME "Itau"

int main()
{
    printf("Bem vindo ao banco %s\n", BANK_NAME);

    addClient("roberto", 34, 'M');
    addClient("sara", 21, 'F');
    addClient("andre", 19, 'M');

    showClients();

    removeClient(2);

    showClients();

    return 0;
}

void menu(){

}

