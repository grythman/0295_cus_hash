#include "my_hash.h"

void ht_init(HashTable *p_ht, int len)
{
    int i;
    p_ht->h = (List *)malloc(sizeof(List) * HASH_TABLE_SIZE);
    for (i = 0; i < HASH_TABLE_SIZE; i++)
        p_ht->h[i].head = p_ht->h[i].tail = NULL;
}

void ht_insert(HashTable *p_ht, HashNode x)
{
    int h = ht_hash(x.key);
    Elm *p_elm = l_search(&p_ht->h[h], x.key);
    if (p_elm == NULL)
        l_push_back(&p_ht->h[h], x);
}

HashNode *ht_search(HashTable *p_ht, const char key[])
{
    int h = ht_hash(key);
    Elm *p_elm = l_search(&p_ht->h[h], key);
    if (p_elm == NULL)
        return NULL;
    else
        return &(p_elm->x);
}

void ht_del(HashTable *p_ht, const char key[])
{
    int h = ht_hash(key);
    Elm *p_elm = l_search(&p_ht->h[h], key);
    if (p_elm != NULL)
        l_erase(&p_ht->h[h], h);
}

void ht_release(HashTable *p_ht)
{
    int i;
    for (i = 0; i < HASH_TABLE_SIZE; i++)
    {
        while (p_ht->h[i].head != NULL)
            l_pop_front(&p_ht->h[i]);
    }
    free(p_ht->h);
}

unsigned long hash(unsigned char *p_ht)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *p_ht++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}

void hashnode_print(FILE *fout, const HashNode *p_ht)
{
    if (p_ht == NULL)
                fprintf(fout, "xooson\n");
        else
                fprintf(fout, "%s\n", p_ht->key);
}
