#ifndef LIB_SHA256_H 
#define LIB_SHA256_H

#include <sstream>
#include <openssl/sha.h>
#include <string>
#include <iomanip>
#include <iostream>

#include "../blockchain/block.hpp"

typedef unsigned char uschar;

std::string calc_hash_block(const std::string str);

size_t calc_nonce_block(std::string nonce);

#endif //LIB_SHA256_H