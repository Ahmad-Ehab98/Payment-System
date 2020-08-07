#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <D:/3rdCSE/Me/Sprints Embedded Booster/types.h>
#include "Terminal.h"

void terminalGet(ST_terminalData_t* terminal)
{
    terminal->maxTransAmount = 5000.00;
    printf("Please Enter Terminal Data:\n");
    printf("Please Enter Transaction Date:\n");
    gets(terminal->transactionDate);
    printf("Please Enter transfer Amount:\n");
    scanf("%f",&terminal->transAmount);
}
bool transDateCheck (ptochar_t transDate,ptochar_t expiryDate)
{
    uint8_t transYear = (transDate[9]-'0')+(transDate[8]-'0')*10;
    uint8_t transMonth = (transDate[4]-'0')+(transDate[3]-'0')*10;
    uint8_t expiryYear = (expiryDate[4]-'0')+(expiryDate[3]-'0')*10;
    uint8_t expiryMonth = (expiryDate[1]-'0')+(expiryDate[0]-'0')*10;
    if (transYear<=expiryYear&&transMonth<expiryMonth)
        return 1;
    else
        return 0;

}

bool maxAmountCheck (ST_terminalData_t* terminal)
{
    if (terminal->transAmount<=terminal->maxTransAmount)
        return 1;
    else
        return 0;
}
