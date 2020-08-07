#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include "Terminal.h"
#include "Card.h"

typedef enum EN_transStat_t
{
    DECLINED,
    APPROVED
}EN_transStat_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t transData;
    EN_transStat_t transStat;
}ST_transaction_t;



#endif // TRANSACTION_H_INCLUDED
