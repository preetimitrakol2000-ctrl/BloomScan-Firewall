#ifndef BLOOM_H
#define BLOOM_H

typedef struct {
    unsigned char* bit_vector;
    int size_in_bits;
} BloomFilter;

BloomFilter* create_filter(int total_bits);
unsigned int hash_alpha(const char* str, int max_bits);
unsigned int hash_beta(const char* str, int max_bits);
void register_threat(BloomFilter* bf, const char* ip);
int check_threat(BloomFilter* bf, const char* ip);
void free_filter(BloomFilter* bf);

#endif
