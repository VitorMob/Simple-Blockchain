#include <blockchain.hpp>

int main()
{        

        Blockchain blocks;
        
        TransactionData data1("elaro", "onion", 10.0);
        blocks.set_Block(data1);

        TransactionData data2("onion", "fall", 9.0);
        blocks.set_Block(data2);

        TransactionData data3("fall", "mob", 7.0);
        blocks.set_Block(data3);
        
return 0;
}