#ifndef LIB_BLOCKCHAIN_H
#define LIB_BLOCKCHAIN_H 

#include <vector>
#include <string>
#include <iostream>

#include "block.hpp"

class Blockchain
{	
	public:
		std::vector<Block> chain;

		Block  		previous_Block();
		void  		set_Block(TransactionData data);
		
		void  		block_Print(Block newBlk);
		std::string is_Chain_Valid();
		
		Blockchain();
};

#endif // LIB_BLOCKCHAIN_H