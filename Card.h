#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include "../types.h"
typedef struct ST_cardData_t
{
 uint8_t cardHolderName[25];
 uint8_t primaryAccountNumber[10];
 uint8_t cardExpirationDate[6];
}ST_cardData_t;

void cardGet (ST_cardData_t* card);




#endif // CARD_H_INCLUDED
