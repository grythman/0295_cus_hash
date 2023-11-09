#ifndef MY_HASH_H
#define MY_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HashNode {
    char key[64]; 
    int value; 
};
typedef struct HashNode HashNode;

struct Elm {
        HashNode x;
        struct Elm *next;
};
typedef struct Elm Elm;

struct List {
    Elm *head;
    Elm *tail;
    int len;
};

typedef struct List List;

struct HashTable {
    List *h;
    int len;
};
#define HASH_TABLE_SIZE 1000000
typedef struct HashTable HashTable;

void ht_init(HashTable *, int len);
void ht_insert(HashTable *, const HashNode );
HashNode *ht_search(HashTable *, const char key[]);
void ht_del(HashTable *, const char key[]);
void ht_release(HashTable *);
unsigned int ht_hash(char key[]);
void hashnode_print(FILE *, const HashNode *);

void l_push_back(List *, HashNode);
HashNode *l_search(List *, const char key[]);
void l_erase(List *, const char key[]);
void l_pop_front(List *);

#endif
