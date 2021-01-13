#ifndef BANKDATABASE_H_INCLUDED
#define BANKDATABASE_H_INCLUDED
#include "client.h"

int createAccount(char* name, int age, char gender);
char* showAccounts();
int charCounter(char* text);

int executeDeposit(int id, float money);
int executeWithdraw(int id, float money);
int executeTransfer(int id, float money, int destinyId);

int locateFreeIndex();
void removeAccount(int id);

#endif // BANKDATABASE_H_INCLUDED
