#include "blockchain.hpp"

Blockchain::Blockchain()
{
    // Create genesis block
    // Add in chain/vector 
    int index = chain.size();
    TransactionData genesis("mob", "onion", 10.0);
    Block genesis_d(index, genesis, "00000");
    chain.push_back(genesis_d);
}

Block Blockchain::previous_Block()
{
    return chain.back();
}

void Blockchain::set_Block(TransactionData data)
{
    int index = chain.size();
    std::string prev_hash =  previous_Block().get_Hash();
    Block newBlk(index, data, prev_hash);
    
    chain.push_back(newBlk);
    Blockchain::block_Print(newBlk);
}

void Blockchain::block_Print(Block newBlk)
{
    for(long unsigned int i=0;i<chain.size()-chain.size()+1;i++)
    {
        std::cout<< "@Block <<" <<std::endl
            << "@Index :" << newBlk.get_Index() <<std::endl
            << "@Sendkey :" << newBlk.data.sendkey  <<std::endl
            << "@Receivekey :" << newBlk.data.recvkey  <<std::endl
            << "@Amount :" << newBlk.data.amount <<std::endl 
            << "@Hash :" << newBlk.generate_Hash() <<std::endl
            << "@vBlock: " << newBlk.get_vBlock()<<std::endl
            << "@PreviousHash :" << newBlk.get_Previous_Hash() <<std::endl
            << "@Validation:" << newBlk.is_Hash_Valid() <<std::endl
            << "@Nonce:" << newBlk.get_Nonce() <<std::endl
            << "@Timestamp: " << newBlk.data.timestamp <<std::endl;
    }
}


