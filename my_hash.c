#include "my_hash.h"

void ht_init(HashTable *p_ht)
{
    int i;
    p_ht->h = (List *)malloc(sizeof(List) * HASH_TABLE_SIZE);
    for (int i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        p_ht->h[i].head = NULL;
        p_ht->h[i].tail = NULL;
        p_ht->h[i].len = 0;
    }
}

void ht_insert(HashTable *p_ht, const HashNode x)
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

unsigned int ht_hash(const char s[])
{
    unsigned int hash = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        hash = (hash * 31) + s[i]; // Using prime number 31 for better distribution
    }
    return hash % TABLE_SIZE;
}
dashka
unsigned int hashFunction(char* key) {
    const float A = 0.618033; // A constant value for multiplication method
    float hashValue = 0;
    int length = strlen(key);
    int i;

    for (i = 0; i < length; i++) {
        hashValue = hashValue + key[i];
    }

    hashValue = hashValue * A;
    hashValue = hashValue - (int)hashValue;
    return (int)(TABLE_SIZE * hashValue);
}
void hashnode_print(FILE *fout, const HashNode *p_ht)
{
    if (p_ht == NULL)
        fprintf(fout, "xooson\n");
    else
        fprintf(fout, "%s\n", p_ht->key);
}
