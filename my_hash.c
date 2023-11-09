#include "my_hash.h"

void ht_init(HashTable *ht, int len)
{
    int i;
    ht->h = (List *)malloc(sizeof(List) * HASH_TABLE_SIZE);
    for (i = 0; i < HASH_TABLE_SIZE; i++)
        ht->h[i].head = ht->h[i].tail = NULL;
}

void ht_insert(HashTable *ht, HashNode x)
{
    int h = ht_hash(x.id);
    Elm *p_elm = l_search(&ht->h[h], x.id);
    if (p_elm == NULL)
        l_push_back(&ht->h[h], x);
}

HashNode *ht_search(HashTable *ht, const char key[])
{
    int h = ht_hash(key);
    Elm *p_elm = l_search(&ht->h[h], key);
    if (p_elm == NULL)
        return NULL;
    else
        return &(p_elm->x);
}

void ht_del(HashTable *ht, const char key[])
{
    int h = ht_hash(key);
    Elm *p_elm = l_search(&ht->h[h], key);
    if (p_elm != NULL)
        l_erase(&ht->h[h], h);
}

void ht_release(HashTable *ht)
{
    int i;
    for (i = 0; i < HASH_TABLE_SIZE; i++)
    {
        while (ht->h[i].head != NULL)
            l_pop_front(&ht->h[i]);
    }
    free(ht->h);
}

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}

void hashnode_print(FILE *fout, const HashNode *p)
{
    fprintf(fout, "%d\n", p->value);
}
