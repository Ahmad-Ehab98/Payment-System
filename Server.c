#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <D:/3rdCSE/Me/Sprints Embedded Booster/types.h>
#include "Server.h"

bool accountNumberCheck (ptochar_t enteredPAN , ST_accountBalance_t* account)
{
    uint8_t count = 0;
    for (uint8_t i=0;i<10;i++)
    {
        if (enteredPAN[i] == account->primaryAccountNumber[i])
                count++;
    }
    if(count == 10)
        return 1;
    else
        return 0;

}

bool balanceCheck (float transAmount,float balance)
{
    if(transAmount<=balance)
        return 1;
    else
        return 0;
}
