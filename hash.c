#include "DS.h"

/*
  Хайш тооцоолох функц: `s` тэмдэгтэн цувааны хайшыг тооцоолоод,
  тооцоолсон хайшыг буцаах функц.
 */
void ht_insert(HashTable *p_hash, const Student x)
{
        int h = ht_hash(x.id);
        Elm *p_elm = l_search(&p_hash->h[h], x.id);
        if (p_elm == NULL)
                l_push_back(&p_hash->h[h], x);
}
void ht_init(HashTable *p_hash)
{
        int i;
        p_hash->h = (List *) malloc(sizeof(List) * HASH_TABLE_SIZE);
        for (i = 0; i < HASH_TABLE_SIZE; i++)
                p_hash->h[i].head = p_hash->h[i].tail = NULL;
}
int ht_hash(const char s[])
{
        int hash = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            hash = (hash * 256 + s[i]) % HASH_TABLE_SIZE;
        }
        return hash;
}

/*
  Хайх функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж,
  олдсон оюутны хаягийг буцаах функц. Олдохгүй бол `NULL` хаяг буцаана.
 */
Student *ht_search(HashTable *p_hash, const char id[])
{
        int h = ht_hash(id);
        Elm *p_elm = l_search(&p_hash->h[h], id);
        if (p_elm == NULL)
                return NULL;
        else
                return &(p_elm->x);
}

/*
  Мэдээлэл өөрчлөх функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `x.id`-аар
  оюутныг хайж олоод, овог нэрийг `x.ner`, `x.ovog`-оор солино.
  Олдохгүй бол `x` оюутныг шинээр оруулна.
 */
void ht_update(HashTable *p_hash, const Student x)
{
        int h = ht_hash(x.id);
        Elm *p_elm = l_search(&p_hash->h[h], x.id);
        if (p_elm != NULL)
        {
                strcpy(p_elm->x.ovog, x.ovog);
                strcpy(p_elm->x.ner, x.ner);
        }
}

/*
  Устгах функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж
  олж устгана. Олдохгүй бол юу ч хийхгүй.
 */
void ht_del(HashTable *p_hash, const char id[])
{
        int h = ht_hash(id);
        Elm *p_elm = l_search(&p_hash->h[h], id);
        if (p_elm != NULL)
                l_erase(&p_hash->h[h], h);
}
void ht_release(HashTable *p_hash)
{
        int i;
        for (i = 0; i < HASH_TABLE_SIZE; i++) {
                while (p_hash->h[i].head != NULL)
                        l_pop_front(&p_hash->h[i]);
        }
        free(p_hash->h);
}
void student_print(FILE *fout, const Student *p)
{
        if (p == NULL)
                fprintf(fout, "xooson\n");
        else
                fprintf(fout, "%s %s %s\n", p->ovog, p->ner, p->id);
}