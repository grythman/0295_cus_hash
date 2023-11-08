#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, Student x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
    Elm *newElm = (Elm *)malloc(sizeof(Elm));
    newElm->x = x;
    newElm->next = NULL;
    if (p->head == NULL) {
        p->head = newElm;
        p->tail = newElm;
    } else {
        p->tail->next = newElm;
        p->tail = newElm;
    }
    p->len++;
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, Student x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
    Elm *newElm = (Elm *)malloc(sizeof(Elm));
    newElm->x = x;
    newElm->next = p->head;
    p->head = newElm;
    if (p->tail == NULL) {
        p->tail = newElm;
    }
    p->len++;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, Student x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
    if (pos <= 0) {
        l_push_front(p, x);
        return;
    }
    if (pos >= p->len) {
        l_push_back(p, x);
        return;
    }
    Elm *newElm = (Elm *)malloc(sizeof(Elm));
    newElm->x = x;
    Elm *current = p->head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }
    newElm->next = current->next;
    current->next = newElm;
    p->len++;
}


/* p-ийн зааж буй List-н эхлэлээс гаргана.
   List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
    if (p->head != NULL) {
        Elm *temp = p->head;
        p->head = p->head->next;
        free(temp);
        if (p->head == NULL) {
            p->tail = NULL;
        }
        p->len--;
    }
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
    if (p->head == NULL) {
        return;
    }
    if (p->head == p->tail) {
        free(p->head);
        p->head = p->tail = NULL;
    } else {
        Elm *current = p->head;
        while (current->next != p->tail) {
            current = current->next;
        }
        free(p->tail);
        p->tail = current;
        current->next = NULL;
    }
    p->len--;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
    if (pos <= 0) {
        l_pop_front(p);
        return;
    }
    if (pos >= p->len - 1) {
        l_pop_back(p);
        return;
    }
    Elm *current = p->head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }
    Elm *temp = current->next;
    current->next = temp->next;
    free(temp);
    p->len--;
}

/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void l_print(List *p)
{
    Elm *current = p->head;
    while (current != NULL) {
        // Modify this line to print the specific values according to your structure
        printf("%s %s %s\n", current->x.ovog, current->x.ner, current->x.id);
        current = current->next;
    }
    printf("\n");
}

/* p-ийн зааж буй List-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
Elm *l_search(List *p, const char id[])
{
	/* Энд хайлтын үйлдлийг хийнэ үү */
    Elm *current = p->head;
    while (current != NULL) {
        if (strcmp(current->x.id, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
