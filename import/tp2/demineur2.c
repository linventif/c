#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int main(void)
{

    WINDOW *mainwin, *childwin;
    int ch;

    /*  Set the dimensions and initial
    position for our child window   */

    int width = 23, height = 7;
    int rows = 25, cols = 80;
    int x = (cols - width) / 2;
    int y = (rows - height) / 2;

    /*  Initialize ncurses  */

    if ((mainwin = initscr()) == NULL)
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
