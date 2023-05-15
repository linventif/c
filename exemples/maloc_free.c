#include <stdio.h>

/* malloc et free sont des fonctions de la librairie stdlib */
/* Il faut donc ajouter cette librairie standard */
#include <stdlib.h>

int main (void)
{
  /* Déclaration du pointeur pt */
  char* pt;

  /* On utilise malloc pour réserver une case mémoire pour un char */
  /* "sizeof(char)" retourne le nombre d'octets utilisés par un char */
  /* Le pointeur pointe donc désormais vers une case mémoire réservée */
  pt = malloc(sizeof(char)); 

  /* Cette case mémoire n'a pas été initialisée et peut contenir n'importe quoi */
  printf("*pt contient %c\n",*pt);

  /* Après initialisation, on peut afficher son contenu */
  *pt = 'B';
  printf("*pt contient %c\n",*pt);

  /* Lorsque l'on a fini de se servir de cette case mémoire, on la libère */
  /* L'instruction free libère la/les cases mémoires ciblées par pt */
  /* Toute case mémoire réservée par malloc doit être libérée par free */
  /* Sinon on obtient ce qui s'appelle une fuite mémoire */
  free(pt);

  /* Une fois la case libérée, elle peut être réutilisée pour autre chose */
  /* Son contenu peut donc varier sans contrôle */
  printf("*pt contient %c\n",*pt);
  
  return 0;

}
