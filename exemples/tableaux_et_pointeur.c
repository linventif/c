#include <stdio.h>

int main (void)
{
  int i;

  /* Ici on déclare et initialise un tableau comme on sait déjà le faire */
  char tab[4] = {'a','b','c','d'};

  /* On déclare aussi un pointeur qui pointe vers la première case du tableau */
  char* pt = &tab[0];

  /* En réalité tab est déjà un pointeur avec la même valeur */
  /* On a donc que la condition pt == tab est vrai */
  if (pt == tab)
    {
      printf("pt == tab\n");
	}
  else
    {
      printf("pt != tab\n");
    }

  /* On peut modifier le tableau soit avec le pointeur défini */  
  *(pt+2) = 'e';

  /* Soit avec le pointeur du tableau */
  /* (On préfèrera cette méthode car cela évite de définir une nouvelle variable) */
  /* L'instruction suivante est équivalente à l'instruction : tab[3] = 'f'; */
  *(tab+3) = 'f';
  
  /* En affichant le tableau, on se rend compte que */
  /* tab[2] et tab[3] on été modifié */
    for (i=0; i<4; i++)
    {
      printf("tab[%d] = %c\n", i, tab[i]);
    }
  
  return 0;
}
