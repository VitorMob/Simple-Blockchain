#include "../blockchain/block.hpp"
#include "../blockchain/blockchain.hpp"
#include <stdlib.h>

// Valid hash the block ?
std::string Block::is_Hash_Valid()
{
	if(get_Hash() == generate_Hash())
        return "True";
    else
        exit(EXIT_FAILURE);
}

std::string Blockchain::is_Chain_Valid()
{
    if(chain.size() == 0 && chain.empty())
        exit(EXIT_FAILURE);
    else
        return "True";
}



