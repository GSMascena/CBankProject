#ifndef BANKDATABASE_H_INCLUDED
#define BANKDATABASE_H_INCLUDED
#include "client.h"

int addClient(char* name, int age, char gender);
void showClients();
int locateFreeIndex();
void removeClient(int id);

#endif // BANKDATABASE_H_INCLUDED
