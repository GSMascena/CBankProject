#include "errorMessage.h"
#include <stdio.h>

void notValidEntry(){
    printf("ERROR: not valid entry\n");
    system("pause");
}

void verifyError(int response){
    switch(response){
    case 0:
        printf("ERROR: not valid id\n");
        break;
    case -1:
        printf("ERROR: not valid account\n");
        break;
    case -2:
        printf("ERROR: not enough balance in account\n");
        break;
    case -3:
        printf("ERROR: not valid destiny id\n");
        break;
    case -4:
        printf("ERROR: not valid destiny account\n");
        break;
    }
    system("pause");
}
