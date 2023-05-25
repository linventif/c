#include <stdio.h>
#include <stdlib.h>

typedef struct liste_t
{
    char c;
    struct liste_t *queue;
} liste_t;

liste_t *add_element_at_end(liste_t *liste, char c);
void show_list(liste_t *liste);
liste_t *add_element_at_begin(char c, liste_t *liste);
char get_head(liste_t *liste);
liste_t *queue_of_list(liste_t *liste);
int is_empty(liste_t *liste);
int size_of_list(liste_t *liste);
liste_t *remove_head(liste_t *liste);
void free_list(liste_t *liste);
liste_t *insert_cara(liste_t *liste, char c, int pos);
liste_t *delete_element(liste_t *liste, int pos);
liste_t *delete_cara(liste_t *liste, char c);
int in_liste(liste_t *liste, char c);
liste_t *inverse_liste(liste_t *liste);
int is_equal(liste_t *liste1, liste_t *liste2);
liste_t *concat_liste(liste_t *liste1, liste_t *liste2);

int main(void)
{
    liste_t *l1 = NULL;
    l1 = add_element_at_end(l1, 'a');
    l1 = add_element_at_end(l1, 'b');
    liste_t *l2 = NULL;
    l2 = add_element_at_end(l2, 'c');
    l2 = add_element_at_end(l2, 'd');
    liste_t *l3 = concat_liste(l1, l2);
    show_list(l3);
    return 0;
}

liste_t *add_element_at_end(liste_t *liste, char c)
{
    if (liste == NULL)
    {
        return add_element_at_begin(c, liste);
    }
    liste->queue = add_element_at_end(liste->queue, c);
    return liste;
}

void show_list(liste_t *liste)
{
    if (liste == NULL)
    {
        return;
    }
    printf("%c", liste->c);
    show_list(liste->queue);
}

liste_t *add_element_at_begin(char c, liste_t *liste)
{
    liste_t *new = malloc(sizeof(liste_t));
    new->c = c;
    new->queue = liste;
    return new;
}

char get_head(liste_t *l) { return l->c; }

liste_t *queue_of_list(liste_t *l) { return l->queue; }

int is_empty(liste_t *l) { return l == NULL; }

int size_of_list(liste_t *l)
{
    if (l == NULL)
    {
        return 0;
    }
    return 1 + size_of_list(l->queue);
}

liste_t *remove_head(liste_t *l)
{
    if (is_empty(l))
    {
        return NULL;
    }
    liste_t *new = l->queue;
    free(l);
    return new;
}

void free_list(liste_t *l)
{
    if (is_empty(l))
    {
        return;
    }
    free_list(l->queue);
    free(l);
}

liste_t *insert_cara(liste_t *l, char c, int pos)
{
    if (pos == 0)
    {
        return add_element_at_begin(c, l);
    }
    if (is_empty(l))
    {
        return NULL;
    }
    l->queue = insert_cara(l->queue, c, pos - 1);
    return l;
}

liste_t *delete_element(liste_t *l, int pos)
{
    if (pos == 0)
    {
        return remove_head(l);
    }
    if (is_empty(l))
    {
        return NULL;
    }
    l->queue = delete_element(l->queue, pos - 1);
    return l;
}

liste_t *delete_cara(liste_t *l, char c)
{
    if (is_empty(l))
    {
        return NULL;
    }
    if (l->c == c)
    {
        return remove_head(l);
    }
    l->queue = delete_cara(l->queue, c);
    return l;
}

int in_liste(liste_t *l, char c)
{
    if (is_empty(l))
    {
        return 0;
    }
    if (l->c == c)
    {
        return 1;
    }
    return in_liste(l->queue, c);
}

liste_t *inverse_liste(liste_t *l)
{
    if (is_empty(l))
    { // Cas ou je suis à la fin de la liste
        return NULL;
    }
    if (is_empty(l->queue))
    { // Cas ou je suis le dernier élément de la liste
        return l;
    }
    liste_t *new = inverse_liste(l->queue);
    l = add_element_at_end(new, l->c);
    return l;
}

int is_equal(liste_t *l1, liste_t *l2)
{
    if (is_empty(l1) && is_empty(l2))
    {
        return 1;
    }
    if (is_empty(l1) || is_empty(l2))
    {
        return 0;
    }
    if (l1->c != l2->c)
    {
        return 0;
    }
    return is_equal(l1->queue, l2->queue);
}

liste_t *concat_liste(liste_t *l1, liste_t *l2)
{
    if (is_empty(l1))
    {
        return l2;
    }
    l1->queue = concat_liste(l1->queue, l2);
    return l1;
}