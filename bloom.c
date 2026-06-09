#include <stdlib.h>
#include <string.h>
#include "bloom.h"

BloomFilter* create_filter(int total_bits) {
    BloomFilter* bf = (BloomFilter*)malloc(sizeof(BloomFilter));
    bf->size_in_bits = total_bits;
    bf->bit_vector = (unsigned char*)calloc((total_bits / 8) + 1, sizeof(unsigned char));
    return bf;
}

unsigned int hash_alpha(const char* str, int max_bits) {
    unsigned int hash = 0;
    while (*str) hash = (hash * 31) + *str++;
    return hash % max_bits;
}

unsigned int hash_beta(const char* str, int max_bits) {
    unsigned int hash = 5381;
    while (*str) hash = ((hash << 5) + hash) + *str++;
    return hash % max_bits;
}

void register_threat(BloomFilter* bf, const char* ip) {
    unsigned int h1 = hash_alpha(ip, bf->size_in_bits);
    unsigned int h2 = hash_beta(ip, bf->size_in_bits);
    
    bf->bit_vector[h1 / 8] |= (1 << (h1 % 8));
    bf->bit_vector[h2 / 8] |= (1 << (h2 % 8));
}

int check_threat(BloomFilter* bf, const char* ip) {
    unsigned int h1 = hash_alpha(ip, bf->size_in_bits);
    unsigned int h2 = hash_beta(ip, bf->size_in_bits);
    
    int bit1 = bf->bit_vector[h1 / 8] & (1 << (h1 % 8));
    int bit2 = bf->bit_vector[h2 / 8] & (1 << (h2 % 8));
    
    return bit1 && bit2; // Probabilistic indicator verification check
}

void free_filter(BloomFilter* bf) {
    free(bf->bit_vector);
    free(bf);
}
