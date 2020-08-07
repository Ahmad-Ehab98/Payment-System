#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <D:/3rdCSE/Me/Sprints Embedded Booster/types.h>
#include "Card.h"
#include "Server.h"
#include "Terminal.h"
#include "Transaction.h"
ST_accountBalance_t serverData [10] = {{100.00,"123456789",0},{6000.00,"234567891",0},{3250.25,"567891234",0},{1500.12,"456789123",0},{500.00,"258649173",0},{2100.00,"654823719",0},{0.00,"971362485",0},{1.00,"793148625",0},{10.12,"123123456",0},{0.55,"456789123",0}};

int main()
{
    uint8_t again = 'y';
    while (again == 'y')
    {
        ST_cardData_t card;
        ST_terminalData_t terminal;
        cardGet(&card);
        terminalGet(&terminal);
        printf("Verifying data from the server ...\n");
        bool dateValid = transDateCheck(&terminal.transactionDate,&card.cardExpirationDate);
        bool maxValid = maxAmountCheck(&terminal);
        bool foundAccount = 0;
        bool balanceValid=0;
        uint8_t accountIndex;
        for (uint8_t i=0;i<10;i++)
        {
            foundAccount = accountNumberCheck(card.primaryAccountNumber,&serverData[i]);
            if (foundAccount)
            {
                 balanceValid = balanceCheck (terminal.transAmount,serverData[i].balance);
                 accountIndex = i;
                 break;
            }
        }
        ST_transaction_t trans ;
        trans.cardHolderData = card;
        trans.transData=terminal;
        if(dateValid&&maxValid&&accountNumberCheck&&balanceValid)
            trans.transStat=1;
        else
            trans.transStat=0;
        if(trans.transStat)
        {
            printf("Transaction is APPROVED\n");
            serverData[accountIndex].balance-=terminal.transAmount;
            printf("Your new balance is %f\n",serverData[accountIndex].balance);
            if (serverData[accountIndex].transactionCount==4)
            {
                serverData[accountIndex].transactionCount=0;
                serverData[accountIndex].transactions[serverData[accountIndex].transactionCount]=trans;
            }
            else
                    serverData[accountIndex].transactions[serverData[accountIndex].transactionCount]=trans;

            printf("Transaction saved, date is %s\n",serverData[accountIndex].transactions[serverData[accountIndex].transactionCount].transData.transactionDate);
            serverData[accountIndex].transactionCount++;

        }
        else
                printf("Transaction is DECLINED\n");

        printf("Do you wish to continue (y/n)?\n");
        scanf("%*c%c%*c",&again);
    }

    return 0;
}
