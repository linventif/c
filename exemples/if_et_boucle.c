#include <stdio.h>

int main (void)
{

  /* Initialisation des variables */

  int i = 0;
  int j = 0;
  int k = 0;


  
  /* Le conditionnel If */

  /* Les conditions sont de la forme suivante : */
  /*   <  pour inférieur strict */
  /*   <= pour inférieur ou égal */
  /*   >  pour supérieur strict */
  /*   >= pour supérieur ou égal */
  /*   == pour l'égalité */
  /*   != pour différent */
  /* ATTENTION : l'égalité s'écrit == */
  /* Le signe = désigne UNIQUEMENT une affectation de variable */

  if (i == 0)
    {
      printf("If : i vaut zéro\n\n");
    }
  else
    {
      printf("If : i vaut %d\n\n",i);
    }


  /* Note : Le bloc else est facultatif */

  if (i == 0)
    {
      printf("If : i vaut toujours zéro\n\n");
    }



  /* La boucle Do While */

  /* La boucle do while effectue le contenu de la boucle une fois */
  /* Puis répète tant que la condition (ici i<4) est réalisée */
  
  printf("début du do while\n");
  do
    {
      printf("Do While : i vaut : %d\n",i);
      i = i+1;
    }
  while (i < 4);
  printf("fin du do while\n");

  /* À la fin de la boucle, la valeur de i est la valeur en quittant la boucle */
  printf("valeur de i : %d\n\n",i);



  /* La boucle While */
  
  /* La boucle while effectue le contenu du bloc à chaque fois */
  /* que la condition (ici j<4) est réalisée */

  printf("début du while\n");
  j=0;
  while (j < 4)
    {
      printf("While : j vaut : %d\n",j);
      j = j+1;
    }
  printf("fin du while\n");

  /* À la fin de la boucle, la valeur de j est la valeur en quittant la boucle */
  printf("valeur de j : %d\n\n",j);


  
  /* La boucle for */

  /* La boucle for est un alias de la boucle while */
  /* La boucle for contient 4 morceaux distincts */
  /* l'instruction "k=0" est effectuée avant le début de la boucle */
  /* la condition "k<4" est testée à chaque tour */
  /* - si elle est fausse, la boucle s'arrête */
  /* - si elle est juste, alors on continue dans la boucle */
  /* l'instruction "k = k+1" est effectuée à la fin de chaque tour de boucle */
  /* Enfin, le contenu entre accolades est la boucle en elle-même */
  
  printf("début du for\n");
  for (k=0; k<4; k = k+1)
    {
      printf("For : k vaut : %d\n",k);
    }
  printf("fin du for\n");

  /* À la fin de la boucle, la valeur de k est la valeur en quittant la boucle */
  printf("valeur de k : %d\n\n",k);


  /* Le conditionnel If */

  if (i == 0)
    {
      printf("If : i vaut zéro\n");
    }
  else
    {
      printf("If : i vaut %d\n",i);
    }


  return 0;
}
