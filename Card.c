#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Card.h"
#include <D:/3rdCSE/Me/Sprints Embedded Booster/types.h>

void cardGet (ST_cardData_t* card)
{
    printf("Please Enter Card Data:\n");
    printf("Please Enter the Card Holder Name:\n");
    gets(card->cardHolderName);
    printf("Please Enter the Primary Account Number:\n");
    gets(card->primaryAccountNumber);
    printf("Please Enter Card Expiry Date:\n");
    gets(card->cardExpirationDate);
}


