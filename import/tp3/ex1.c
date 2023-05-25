#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char *tab;
    int size;
} super_tableau_t;

typedef super_tableau_t chaine_t;

// Exercice 1
char *new_tab(int size);
void initialize_tab(char *tab, int size, char cara);
void show_tab(char *tab, int size);
void free_tab(char *tab);
int out_of_range(int size, int index);
void set_on_tab(char *tab, int size, int index, char cara);
char get_in_tab(char *tab, int size, int index);
// Exercice 2
super_tableau_t *new_super_tab(int size);
void initialize_super_tab(super_tableau_t *super_tab, char cara);
void show_super_tab(super_tableau_t *super_tab);
void free_super_tab(super_tableau_t *super_tab);
void set_in_super_tab(super_tableau_t *super_tab, int index, char cara);
char get_in_super_tab(super_tableau_t *super_tab, int index);
int size_super_tab(super_tableau_t *super_tab);
// Exercice 3
int chaine_is_valid(chaine_t *chaine);
int size_of_chaine(chaine_t *chaine);
void show_chaine(chaine_t *chaine);
void add_cara(chaine_t *chaine, char c);
void elongated_chaine(chaine_t *chaine);
void add_chaine(chaine_t *chaine, chaine_t *chaine2);
void lire_entree_utilisateur(chaine_t *chaine);
void insert_cara(chaine_t *chaine, char c, int index);
void insert_chaine(chaine_t *chaine, chaine_t *chaine2, int index);
void delete_cara(chaine_t *chaine, int index);
void delete_chaine(chaine_t *chaine, int index_start, int index_end);
int egal(chaine_t *chaine, chaine_t *chaine2);
int empty(chaine_t *chaine);
void replace(chaine_t *chaine, char c_old, char c_new);
void to_lower_case(chaine_t *chaine);
void to_upper_case(chaine_t *chaine);
void start_with_upper_case(chaine_t *chaine);
int index_of(chaine_t *chaine, char c);

int main(void)
{
    // Exercice 1
    /*char* tab = new_tab(4);
    initialize_tab(tab, 4, 'a');
    *(tab + 1) = 'e';
    show_tab(tab, 4);
    set_on_tab(tab, 4, 1, 't');
    set_on_tab(tab, 4, 5, 'u');
    show_tab(tab, 4);
    return 0;*/

    // Exercice 2

    /*super_tableau_t* super_tab;
    super_tab = new_super_tab(4);
    initialize_super_tab(super_tab, 'a');
    set_in_super_tab(super_tab, 1, 'e');
    show_super_tab(super_tab);
    set_in_super_tab(super_tab, 1, 't');
    set_in_super_tab(super_tab, 5, 'u');
    show_super_tab(super_tab);*/

    // Exercice 3
    chaine_t *chaine = new_super_tab(1);
    lire_entree_utilisateur(chaine);
    show_chaine(chaine);
    return 0;
}

char *new_tab(int size)
{
    char *tab;
    tab = malloc(size * sizeof(char));
    return tab;
}

void initialize_tab(char *tab, int size, char cara)
{
    for (int i = 0; i < size; ++i)
    {
        *(tab + i) = cara;
    }
}

void show_tab(char *tab, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%c ", *(tab + i));
    }
}

void free_tab(char *tab) { free(tab); }

int out_of_range(int size, int index) { return index < 0 || index >= size; }

void set_on_tab(char *tab, int size, int index, char cara)
{
    if (out_of_range(size, index))
    {
        printf("Index out of range");
        exit(1);
    }
    *(tab + index) = cara;
}

char get_in_tab(char *tab, int size, int index)
{
    if (out_of_range(size, index))
    {
        printf("Index out of range");
        exit(1);
    }
    return *(tab + index);
}

super_tableau_t *new_super_tab(int size)
{
    super_tableau_t *super_tab = malloc(sizeof(super_tableau_t));
    super_tab->size = size;
    super_tab->tab = new_tab(size);
    return super_tab;
}

void initialize_super_tab(super_tableau_t *super_tab, char cara) { initialize_tab(super_tab->tab, super_tab->size, cara); }

void show_super_tab(super_tableau_t *super_tab) { show_tab(super_tab->tab, super_tab->size); }

void free_super_tab(super_tableau_t *super_tab)
{
    free_tab(super_tab->tab);
    free(super_tab);
}

void set_in_super_tab(super_tableau_t *super_tab, int index, char cara) { set_on_tab(super_tab->tab, super_tab->size, index, cara); }

char get_in_super_tab(super_tableau_t *super_tab, int index) { return get_in_tab(super_tab->tab, super_tab->size, index); }

int size_super_tab(super_tableau_t *super_tab) { return super_tab->size; }

int size_of_chaine(chaine_t *chaine)
{
    int i = 0;
    while (i < chaine->size && chaine->tab[i] != '\0')
    {
        i++;
    }
    return i;
}

int chaine_is_valid(chaine_t *chaine)
{
    return size_of_chaine(chaine) < chaine->size;
}

void show_chaine(chaine_t *chaine)
{
    for (int i = 0; i < size_of_chaine(chaine); ++i)
    {
        printf("%c", chaine->tab[i]);
    }
    printf("\n");
}

void add_cara(chaine_t *chaine, char c)
{
    if (!chaine_is_valid(chaine))
    {
        elongated_chaine(chaine);
    }
    int pos = size_of_chaine(chaine);
    chaine->tab[pos] = c;
    chaine->tab[pos + 1] = '\0';
}

void elongated_chaine(chaine_t *chaine)
{ // Possibilité de faire un realloc mais pas autorisé !
    chaine->size += 1;
    char *tab = new_tab(chaine->size);
    for (int i = 0; i < chaine->size; ++i)
    {
        tab[i] = chaine->tab[i];
    }
    tab[size_of_chaine(chaine)] = '\0';
    free_tab(chaine->tab);
    chaine->tab = tab;
}

void add_chaine(chaine_t *chaine, chaine_t *chaine2)
{
    for (int i = 0; i < size_of_chaine(chaine2); ++i)
    {
        add_cara(chaine, chaine2->tab[i]);
    }
}

void lire_entree_utilisateur(chaine_t *chaine)
{
    char c;
    while ((c = getchar()) != '\n')
    {
        add_cara(chaine, c);
    }
}

void insert_cara(chaine_t *chaine, char c, int index)
{
    if (!chaine_is_valid(chaine))
    {
        elongated_chaine(chaine);
    }
    for (int i = size_of_chaine(chaine); i > index; --i)
    {
        chaine->tab[i] = chaine->tab[i - 1];
    }
    chaine->tab[index] = c;
}

void insert_chaine(chaine_t *chaine, chaine_t *chaine2, int index)
{
    for (int i = 0; i < size_of_chaine(chaine2); ++i)
    {
        insert_cara(chaine, chaine2->tab[i], index + i);
    }
}

void delete_cara(chaine_t *chaine, int index)
{
    for (int i = index; i < size_of_chaine(chaine); ++i)
    {
        chaine->tab[i] = chaine->tab[i + 1];
    }
}

void delete_chaine(chaine_t *chaine, int index_start, int index_end)
{
    for (int i = index_start; i < index_end; ++i)
    {
        delete_cara(chaine, index_start);
    }
}

int egal(chaine_t *chaine, chaine_t *chaine2)
{
    if (size_of_chaine(chaine) != size_of_chaine(chaine2))
    {
        return 0;
    }
    for (int i = 0; i < size_of_chaine(chaine); ++i)
    {
        if (chaine->tab[i] != chaine2->tab[i])
        {
            return 0;
        }
    }
    return 1;
}

int empty(chaine_t *chaine) { return size_of_chaine(chaine) == 0; }

void replace(chaine_t *chaine, char c, char c2)
{
    for (int i = 0; i < size_of_chaine(chaine); ++i)
    {
        if (chaine->tab[i] == c)
        {
            chaine->tab[i] = c2;
        }
    }
}

void to_lower_case(chaine_t *chaine)
{
    for (int i = 0; i < size_of_chaine(chaine); ++i)
    {
        if (chaine->tab[i] >= 'A' && chaine->tab[i] <= 'Z')
        {
            chaine->tab[i] += 'a' - 'A';
        }
    }
}

void to_upper_case(chaine_t *chaine)
{
    for (int i = 0; i < size_of_chaine(chaine); ++i)
    {
        if (chaine->tab[i] >= 'a' && chaine->tab[i] <= 'z')
        {
            chaine->tab[i] -= 'a' - 'A';
        }
    }
}

void to_upper_case_first(chaine_t *chaine)
{
    if (chaine->tab[0] >= 'a' && chaine->tab[0] <= 'z')
    {
        chaine->tab[0] -= 'a' - 'A';
    }
}

int index_of(chaine_t *chaine, char c)
{
    for (int i = 0; i < size_of_chaine(chaine); ++i)
    {
        if (chaine->tab[i] == c)
        {
            return i;
        }
    }
    return -1;
}