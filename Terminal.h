#ifndef TERMINAL_H_INCLUDED
#define TERMINAL_H_INCLUDED
#include "../types.h"

typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

void terminalGet(ST_terminalData_t * terminal);
bool transDateCheck (ptochar_t transDate,ptochar_t expiryDate);
bool maxAmountCheck (ST_terminalData_t* terminal);


#endif // TERMINAL_H_INCLUDED
