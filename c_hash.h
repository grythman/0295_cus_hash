#ifndef C_HASH_H
#define C_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 1000000

struct HashTable {
        List *h;
        int len;
};
typedef struct HashTable HashTable;

#endif
