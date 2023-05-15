#include <stdio.h>

int main (void)
{
  /* Nous déclarons i comme étant un entier (de valeur 66). */
  int i = 66;

  /* Mais au moment de l'afficher, nous l'affichons une première fois comme un entier (%d) et une seconde fois comme un caractère (%c) */
  /* Lorsqu'il est affiché comme un entier, nous observons bien la valeur 66 */
  /* Mais lorsqu'il est affiché comme un caractère, nous observons le caractère 'B' */
  /* car le code ascii de 'B' est, en décimal, 66 (rappel : man ascii) */
  printf(" i : %d : %c\n", i, i);

  /* Conclusion, un entier peut être converti en caractère. En fait tout peut être converti en tout */
  /* ATTENTION : il est recommandé de NE PAS UTILISER ces conversions de type */
  /* car leur comportement cache des surprises à qui ne maitrise pas totalement le langage C. */
  
  return 0;
}
