#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include "client.h"

typedef struct t_account{
    int id;
    Client client;
    float deposit;
    int isValid;
} Account;

#endif // ACCOUNT_H_INCLUDED
