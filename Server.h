#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include "../types.h"
#include "Transaction.h"
typedef struct ST_accountBalance_t
{
    float balance;
    uint8_t primaryAccountNumber[10];
    uint8_t transactionCount;
    ST_transaction_t transactions [5];
}ST_accountBalance_t;

bool accountNumberCheck (ptochar_t enteredPAN , ST_accountBalance_t* account);

bool balanceCheck (float transAmount,float balance);


#endif // SERVER_H_INCLUDED
