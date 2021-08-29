#ifndef LIB_TRANSACTION_H
#define LIB_TRANSACTION_H

#include <string>
#include <time.h>
#include <iostream>

struct TransactionData
{
    std::string recvkey;
    std::string sendkey;
    std::string timestamp;
    double amount;    

    TransactionData(){};
    TransactionData(std::string cvkey, std::string endkey, double amnt)
    { 
        time_t result = time(NULL);
        timestamp = asctime(localtime(&result));
        recvkey=cvkey;
        sendkey=endkey;
        amount=amnt;
    }
};


#endif // LIB_TRANSACTION_H