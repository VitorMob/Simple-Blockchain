#include "block.hpp"

std::string Block::generate_Hash()
{
    std::string  theHash =
		    data.sendkey+
		    data.recvkey+
		    std::to_string(data.amount)+
	    	data.timestamp;
	        return calc_hash_block(theHash);

}

size_t Block::compute_hash_with_proof_of_work(std::string difficulty)
{
    std::string  nonce =
		    data.sendkey+
		    data.recvkey+
		    std::to_string(data.amount)+
	    	data.timestamp;
    
    while(true)
    {
        uschar calc_c = calc_nonce_block(nonce);
        if(nonce != difficulty){
            return calc_c;
        }else
            nonce+=1;
    }
}

Block::Block(int idx, TransactionData d, std::string prev_hash)
{
    index=idx;
    data=d;
    previous_hash=prev_hash;
    hash=generate_Hash();
    nonce=compute_hash_with_proof_of_work("00");
    vBlock=nVersion;
}

double Block::get_vBlock()
{
    return vBlock;
}

size_t Block::get_Index()
{
    return index;
}

std::string Block::get_Hash()
{
    return hash;
}

std::string Block::get_Previous_Hash()
{    
    return previous_hash; 
}

size_t Block::get_Nonce()
{
    return nonce;
}