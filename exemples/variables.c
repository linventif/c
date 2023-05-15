/* Dans cet exemple nous allons définir des variables et les afficher. */

#include <stdio.h>

int main (void)
{

  /* Les nombres entiers sont des "int". Ici on déclare nombre comme étant un "int" et on initialise à 8 */
  int nombre = 8;
  /* Les nombres à virgule sont des "float". Ici on déclare prix comme étant un "float" et on initialise à 2.5 */
  float prix = 2.5;
  /* Les lettres sont des "char". Attention une lettre est entourée de simples guillemets */
  char lettre = 'P';
  /* Les chaines de caractères sont un peu spéciale, nous reviendrons dessus en détail. */
  /* Pour faire simple, c'est un tableau de "char", d'où la nécessité du [] pour indiquer que c'est un tableau */
  /* La chaine est entourée de doubles guillemets */
  char fruit[] = "Pommes";

  /* ATTENTION : toujours initialiser vos variables sinon elles peuvent contenir n'importe quoi */
  /* Souvant ça sera 0, mais pas toujours */


  /* Pour afficher une variable, on utilise printf dans lequel on écrit %s, %c, %d ou %f, puis comme deuxième argument, la variable à afficher */
  /* Le choix du % dépend du type de la variable :*/
  /* %s pour une chaine de caractères */
  /* %c pour un caractère */
  /* %d pour un entier */
  /* %f pour un nombre à virgule */

  printf("J'aime les %s\n", fruit);
  printf("avec un grand %c.\n", lettre);
  printf("J'en ai acheté %d au marché,\n",nombre);
  printf("ça m'a couté %f euros,\n",prix);

  /* Il est possible de forcer le nombre de chiffres affichés en ajoutant un nombre entre le % et le f */
  printf("Ou devrais-je dire %.2f euros\n",prix);


  /* Note : On peut insérer plusieurs variables dans un même texte de printf */
  printf("Au final, j'ai mangé les %d %s\n", nombre, fruit);

  return 0;
}
