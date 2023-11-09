#ifndef MY_HASH_H
#define MY_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HashNode {
    char key[50]; 
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

void ht_init(HashTable *);
void ht_insert(HashTable *, const HashNode);
HashNode *ht_search(HashTable *, const char key[]);
void ht_del(HashTable *, const char key[]);
void ht_release(HashTable *);
int ht_hash(const char key[]);
void hashnode_print(FILE *, const HashNode *);

void l_push_back(List *, HashNode);
void l_push_front(List *, HashNode);
void l_insert(List *, HashNode, int);
void l_pop_front(List *);
void l_pop_back(List *);
void l_erase(List *, int);
void l_print(List *);
Elm *l_search(List *, const char []);

#endif
