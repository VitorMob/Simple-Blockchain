#ifndef LIB_BLOCK_H
#define LIB_BLOCK_H

#include <iostream>
#include <string>
#include <stdio.h>

#include "transaction.hpp"
#include "../crypto/sha256.hpp"
#include "version.hpp"

class Block
{
	private:

		double  vBlock;
		int     index;
		size_t  nonce;
        std::string  hash;
        std::string  previous_hash;

	public:
	
		Block(int idx, TransactionData d, std::string prev_hash);
		std::string 	is_Hash_Valid();
		size_t  		compute_hash_with_proof_of_work(std::string difficulty);

		std::string 	generate_Hash();
		size_t 			get_Index();
		size_t  		get_Nonce();
		std::string 	get_Hash();
		std::string 	get_Previous_Hash();
		double  		get_vBlock();

        TransactionData data;

};

#endif // LIB_BLOCK_H