#include "sha256.hpp"

std::string calc_hash_block(const std::string str)
{
        uschar *hash = SHA256((const unsigned char*)str.c_str(), str.size(), nullptr);
        std::stringstream ss;

        for(int i=0;i<SHA256_DIGEST_LENGTH;i++)
                ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        return ss.str();
}

size_t calc_nonce_block(std::string nonce)
{
        uschar *nonce_calc = SHA256((const unsigned char*)nonce.c_str(), nonce.size(), nullptr);
        return *nonce_calc;
}