/* Ajout des librairies standards */

/* stdio.h permet d'utiliser printf */
#include <stdio.h>

/* Lors de l'exécution du programme c'est "main" qui est exécutée */
/* Pour le moment on l'appellera toujours de la manière suivante "int main (void)" */
/* suivit entre accolades {} de l'ensemble des instructions à exécuter */

int main (void)
{
  /* La seule instruction de notre programme ici est d'afficher "Hello World:!\" */
  /* Pour cela on appelle la fonction d'affichage "printf" et on lui donne comme paramètre la chaine de caractère voulue. */
  /* ATTENTION : Toutes les instructions finissent par un ; */
  printf("Hello world!\n");

  /* le "int" dans "int main (void)" signale que l'on doit retourner un entier */
  /* cet entier est le code d'erreur du programme, il annonce le "nombre d'erreurs" rencontrer par le programme */
  /* Si l'on arrive jusqu'ici, c'est que l'on a réussi donc on retourne 0 */
  /* ATTENTION : Votre programme doit toujours finir par un "return 0;" pour indiquer la réussite */
  return 0;
}

/* Pour compiler on exécute la commande : "gcc -Wall main.c" */
/* Cela produit un fichier exécutable appelé a.out */
/* que l'on peut ensuite exécuter en écrivant ./a.out */
/* ATTENTION : Contrairement aux TPs de système, il faudra rajouter le "./" */
/* car le chemin n'est pas ajouté dans la variable bash PATH */

/* Vous pouvez aussi forcer le nom de l'exécutable avec l'option -o de gcc */
/* Exemple : "gcc -Wall -o hello main.c" va produire l'exécutable "hello" */
