#include "my_hash.h"

void l_push_back(List *p, HashNode x)
{
    Elm *newElm = (Elm *)malloc(sizeof(Elm));
    newElm->x = x;
    newElm->next = NULL;
    if (p->head == NULL)
    {
        p->head = newElm;
        p->tail = newElm;
    }
    else
    {
        p->tail->next = newElm;
        p->tail = newElm;
    }
    p->len++;
}

Elm *l_search(List *p, const char key[])
{
    Elm *current = p->head;
    while (current != NULL) {
        if (strcmp(current->x.key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void l_erase(List *p, int pos)
{
    if (pos <= 0)
    {
        l_pop_front(p);
        return;
    }
    if (pos >= p->len - 1)
    {
        l_pop_back(p);
        return;
    }
    Elm *current = p->head;
    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }
    Elm *temp = current->next;
    current->next = temp->next;
    free(temp);
    p->len--;
}

void l_pop_front(List *p)
{
    if (p->head != NULL)
    {
        Elm *temp = p->head;
        p->head = p->head->next;
        free(temp);
        if (p->head == NULL)
        {
            p->tail = NULL;
        }
        p->len--;
    }
}

void l_pop_back(List *p)
{
    if (p->head == NULL)
    {
        return;
    }
    if (p->head == p->tail)
    {
        free(p->head);
        p->head = p->tail = NULL;
    }
    else
    {
        Elm *current = p->head;
        while (current->next != p->tail)
        {
            current = current->next;
        }
        free(p->tail);
        p->tail = current;
        current->next = NULL;
    }
    p->len--;
}
void l_print(List *p)
{
    Elm *current = p->head;
    while (current != NULL)
    {
        printf("%s\n", current->x.key);
        current = current->next;
    }
    printf("\n");
}