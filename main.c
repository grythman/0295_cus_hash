#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_hash.h"

int main()
{
        HashTable htable;
        ht_init(&htable);
        //ht_init(&htable, HASH_TABLE_SIZE); 
        int n, i, j, m;
        FILE *fin;
        fin = fopen("student.info", "r");
        if (fin == NULL)
        {
                printf("student.info file oldsongui\n");
                exit(1);
        }
        fscanf(fin, "%d", &n);
        HashNode x, *p;
        for (i = 0; i < n; i++)
        {
                fscanf(fin, "%s", x.key);
                ht_insert(&htable, x);
        }
        fclose(fin);
        fin = fopen("input.txt", "r");
        char cmd[10];
        fscanf(fin, "%d", &m);
        FILE *fout = fopen("output.txt", "w");

        for (i = 0; i < m; i++)
        {
                fscanf(fin, "%s", cmd);
                if (strcmp(cmd, "search") == 0)
                {
                        fscanf(fin, "%s", x.key);
                        p = ht_search(&htable, x.key);
                        hashnode_print(fout, p);
                }
                else if (strcmp(cmd, "delete") == 0)
                {
                        fscanf(fin, "%s", x.key);
                        ht_del(&htable, x.key);
                }
        }
        fclose(fin);
        fclose(fout);
        ht_release(&htable);
        return 0;
}
